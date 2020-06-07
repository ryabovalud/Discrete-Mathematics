#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->answer->setReadOnly(true);
    ui->answer1->setReadOnly(true);
    ui->way->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int N,//Количество маршрутов
    M;//Количество остановок
int to=0, from=0;
const int n=20;

int mass[n][n];//матрица инцидентности
int marshryt[n][n];//матрица маршрутов

//Объявление стека в виде массива
struct stack
{
  int elem[n];
  int top;//Индекс последнего элемента в массиве
};


            //*ФУНКЦИИ*

//Функция считывания информации из файла
QString MainWindow::readFile()
{
    QFile file("C:\\Users\\brrri\\OneDrive\\Study\\Alg Diskr Math\\LB\\LB3-GRAF\\GRAF.txt"); // создаем объект класса QFile
    if (!file.open(QIODevice::ReadOnly)) // Проверяем, возможно ли открыть наш файл для чтения
    {
        ui->answer->insertPlainText("\nCANT OPEN FILE\n");// если это сделать невозможно, то завершаем функцию
        return 0;
    }
    else
    {
        QByteArray data; // Создаем объект класса QByteArray, куда мы будем считывать данные из файла
        data = file.readAll(); //считываем все данные с файла в объект data
        ui->answer->insertPlainText("\nINFO IS FINE\n");
        file.close();
        return QString(data);
    }

}

//Поместить элемент в стек
void MainWindow::push(struct stack *stk, int f)
{


        stk->top+=1;
        stk->elem[stk->top] = f;

}


//Показать верхушку стека
int MainWindow::show_top(struct stack *stk)
{
  if((stk->top) >= 0)
  {
    int elem=stk->elem[stk->top];
    return(elem);
  }
  else
  {
    return 0;
  }
}

//Извлечение (удаление)  элемента из стека
void MainWindow::del(struct stack *stk)
{
  if((stk->top) >= 0)
  {
    stk->top-=1;
  }

}

//Вывод элементов стека
void MainWindow::print(struct stack *stk)
{
  if(stk->top)
    {
      ui->answer->clear();
      ui->answer->insertPlainText("YES: \n");
      for(int i=1;i<=stk->top;i++)
        {

          ui->answer->insertPlainText(QString::number(stk->elem[i]) + "->");
        }
    }
  else
  {
      ui->answer->clear();
      ui->answer->insertPlainText("NO\n:(\n:(\n:(\n:(");
  }


}


            //КНОПКИ

/*CLEAR-очистка*/
void MainWindow::on_clear_clicked()
{
    ui->answer->clear();
    ui->answer1->clear();
    ui->way->clear();
    ui->comboBox_FROM->clear();
    ui->comboBox_TO->clear();
}

/*INFO-Получаем информацию*/
void MainWindow::on_pushButton_INFO_clicked()
{

    QString info=readFile();
    if (info!="0")
    {
        QString elem;
        int i,j;

        elem =info.at(0);
        N=elem.toInt();
        elem =info.at(3);
        M=elem.toInt();

        //Обнуляем матрицу маршрутов
        for(int i=0;i<N;i++)
            for(j=0;j<M+1;j++)
                marshryt[i][j]=-1;

        int k=6;
        int x=0, y=0;
        while(info.at(k)!=';')
        {
            elem =info.at(k);
            i=elem.toInt();
            elem =info.at(k+1);
            j=elem.toInt();

            if(i!=0)
            {
               marshryt[x][y]=i;
               y++;
            }

            if(info.at(k)==',')
            {
              x++;
              y=0;
            }


            if(j*i!=0)
            {
                if (mass[i-1][j-1]!=0)//из А в В и из В в А есть путь
                {
                    mass[i-1][j-1] = 2;
                    mass[j-1][i-1] = 2;
                }
                else
                {
                    mass[i-1][j-1] = 1;
                    mass[j-1][i-1] = -1;
                }

            }

            k++;
        }
        ui->answer->clear();

        //ВЫВодиМ матрицу маршрутов
        for(int i=0;i<N;i++)
        {for(j=0;j<M+1;j++)
                if(marshryt[i][j]+1)
                    ui->answer1->insertPlainText(QString::number(marshryt[i][j])+"-->");
         ui->answer1->insertPlainText("\n");
        }

        ui->comboBox_FROM->clear();
        ui->comboBox_TO->clear();
        for(int i=0;i<M;i++)
            ui->comboBox_FROM->insertItem(i,QString::number(i+1));
        for(int i=0;i<M;i++)
        {
            ui->comboBox_TO->insertItem(i,QString::number(i+1));
        }

    }

}

/*PTY - прокладываем путь*/
void MainWindow::on_pushButton_PTY_clicked()
{
     from = ui->comboBox_FROM->currentText().toInt();
     to = ui->comboBox_TO->currentText().toInt();
    ui->way->clear();
    ui->way->insert("\nFROM: " + QString::number(from) + "  \nTO: " + QString::number(to));
    if(!(to-from))
    {
        ui->answer->clear();
        ui->way->clear();
        ui->way->insert("$$$$$FROM=TO$$$$$");
    }
    else
    {
        int x[M];//массив отметок вершин
        int v=from, u=0;
        //Вначале все вершины не отмечены
        for(int i=0;i<M;i++)
            x[i]=0;
        stack *T=new stack;
        T->top=0;//обнуляем список вершин - стек
        push(T,v);//Помещаем начало маршрута в структуру данныx
        x[v-1]=1;//отмечаем начальную вершину
        bool if_push=false;
        while(1)
        {
           if_push = false;
           u=show_top(T);
           if (u==to)break;

           for(int j=0;j<M;j++)
           {
               if ((mass[u-1][j]>=1)&&(x[j]==0))
               {
                  push(T,j+1);
                  x[j]=1;
                  if_push=true;
               }

           }

           if(!if_push) del(T);

           if (T->top==0)break;
        }
        print(T);





    }

}
/*ВЫход*/
void MainWindow::on_pushButton_clicked()
{
    exit(0);
}
