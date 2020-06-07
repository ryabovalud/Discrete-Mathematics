#include "widget.h"
#include "ui_widget.h"
#include "math.h"
#include "QStandardItemModel"
#include "QStandardItem"
QStandardItemModel *model_T = new QStandardItemModel; //������� �����
QStandardItemModel *model_Sm = new QStandardItemModel; //������� ���������
QStandardItemModel *model_H = new QStandardItemModel; //������� ���������

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->T_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->Sm_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->lineEdit->setText("2");
}

Widget::~Widget()
{
    delete ui;
}

int **I,//������� ������� �������������
    **Sm,//������� ������� ���������
    **T,//������� ���� �����
    **H,//������� ����� �����
    *e;//�������������� ������

int N=0,M=0;//���������� ������ � ����
const int n=20;//������������ ���������� ���������� � �����


//������ ����
void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);


  QPainter painter(this);
  painter.begin(this);
  painter.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));

  float x[N],y[N];//���������� ����� - ������ i-�� �������
  float alpha = 2*M_PI/N;
  int x0 = 919/4, y0 = 614/4, R=100,//������ �����
                                        r= 10;

     for(int i = 1; i<=N ; i++) //������ N ������ �������
     {
          x[i]= x0+R*cos(i*alpha);

          y[i]= y0+R*sin(i*alpha);
       QPoint center(x[i],y[i]);
        painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap));
         painter.drawEllipse(center,r,r);
         painter.drawText(x[i]-r/2,y[i]+r/2,QString::number(i));
     }

//������ ����
     int from=0,to=0;
     for (int j =1;j<=M;j++)//�������
     {
         from=0;
         for (int i=1;i<=N;i++)//������
         {
            if(I[i-1][j-1]==1)
            {
                if(!from) from=i;
                else to=i;
            }
         }

         //������ �����
         painter.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));
         float x_1,x_2,y_1,y_2;
         x_1= x[from]+r*cos(to*alpha);y_1= y[from]+r*sin(to*alpha);
         x_2= x[to]+r*cos(from*alpha);y_2= y[to]+r*sin(from*alpha);
           painter.drawLine(x_1, y_1, x_2, y_2);
      }



}


void Widget::on_pushButton_clicked()
{
    //���������e ���������� �� �����
    QFile file("C:\\Users\\brrri\\OneDrive\\Study\\Alg Diskr Math\\LB\\LB4-Graf_Ponytiy\\graf.txt"); // ������� ������ ������ QFile
    if (file.open(QIODevice::ReadOnly)) // ���������, �������� �� ������� ��� ���� ��� ������
        {
            QTextStream in(&file);
            in >> N; // ��������� N - ���������� ������
            in >> M; //� ���������� ����
            //���������� ������ ��� ������� �������������
            I=new int* [N];
              for (int i=0;i<N;i++)
                 I[i]=new int[M];
            for (int i=0;i<N;i++)
                for(int j=0;j<M;j++)
                {
                    in>>I[i][j];
                }
             file.close();
        }

    //������ ������� ���������
    //������ ��� �������
        Sm=new int* [N];
          for (int i=0;i<N;i++)
             Sm[i]=new int[N];
    int from,to;

    for (int i=0;i<N;i++)//������
        for (int j =0;j<N;j++)//�������
        {
            Sm[i][j]=0;
        }

    for (int j =0;j<M;j++)//�������
    {
        from=-1;
        for (int i=0;i<N;i++)//������
        {
           if(I[i][j]==1)
           {
               if(from==-1) from=i;
               else to=i;
           }
        }

        Sm[from][to]=1;Sm[to][from]=1;
    }

    //������ ������ ��������� �����
    ui->textEdit->clear();
    for (int i=0;i<N;i++)//������
    {
        ui->textEdit->insertPlainText("\n"+QString::number(i+1)+" smegno k  ");
        for (int j =0;j<N;j++)//�������
        {
            if(Sm[i][j])
            {
                ui->textEdit->insertPlainText(QString::number(j+1)+",");

            }
        }
    }

//�� ��������� ������ ���� ��������� ����
//������ ������� ���� ����� � ����� �����
    int C[N][N];//������� ���� ����� (��������� ����)
    for(int i=0;i<N;i++)
       for(int j=0;j<N;j++)
       {
            C[i][j]=0;
       }
    for(int i=0;i<N;i++)
       for(int j=0;j<N;j++)
       {
           if(i!=j)
           {
               if (Sm[i][j])
                    C[i][j]=1;//����� ���� �� ����� �������� �� ������ =1
               else C[i][j]=-1;
           }

       }
    int v=N;//���������� ������
    T=new int* [v];
   for (int i=0;i<v;i++)
       T[i]=new int[v]; //������� ���� �����
   H=new int* [v];
   for (int i=0;i<v;i++)
       H[i]=new int[v]; //������� ����� �����
   for(int i=0;i<v;i++)
      for(int j=0;j<v;j++)
      {
          H[i][j]=0;
      }

   for(int i=0;i<v;i++)
      for(int j=0;j<v;j++)
      {
          T[i][j]=C[i][j];//�������������
          if (C[i][j] == -1)
                  H[i][ j] = 0;// { ��� ���� �� i � j }
       }
    for(int k=0;k<v;k++)
    {
      for(int i=0;i<v;i++)
      {
        for (int j=0;j<v;j++)
        {
           if ((i!= j) && (T[i][k] != -1)&&  (T[k][j]!= -1))
           {
              if(T[i][j]==-1)
              {

                   T[i][j]=T[i][k]+T[k][j];
                   H[i][j] = k+1;
              }
              else
               {
                  if(T[i][j]> T[i][k] + T[k][j])
                  {     T[i][j]=T[i][k] + T[k][j];
                        H[i][j] = k+1; //{ ��������� ����� ���� }
                  }
               }
            }
         }
      }
    }

    //���� ������������� ������
    e=new int [N];
    int max=0;
    for (int i=0;i<N;i++)//������
    {
        for (int j =0;j<N;j++)//�������
        {
            if(T[i][j]>max) max=T[i][j];
        }
        e[i]=max;
        max=0;
    }

    //���� ������� ����� � ������
    int d=e[0], r=e[0];
    for(int i=1;i<N;i++)
    {
        if(e[i]>d) d=e[i];
        if(e[i]<r&&e[i]!=0) r=e[i];
    }




    //���������� ������� Sm ���������
    QStandardItem *item;
    model_Sm->clear();

    //��������� ��������
    QStringList horizontalHeader;
    for(int i=1;i<=N;i++) horizontalHeader.append(QString::number(i));

    //��������� �����
    QStringList verticalHeader;
    for(int i=1;i<=N;i++) verticalHeader.append(QString::number(i));



    model_Sm->setHorizontalHeaderLabels(horizontalHeader);
    model_Sm->setVerticalHeaderLabels(verticalHeader);


      for(int i=0;i<N;i++)
      {
        for(int j=0;j<N;j++)
        {
            item = new QStandardItem(QString::number(Sm[i][j]));
            model_Sm->setItem(i, j, item);
        }
      }
      ui->Sm_tableView->setModel(model_Sm);
      ui->Sm_tableView->resizeRowsToContents();
      ui->Sm_tableView->resizeColumnsToContents();



    //���������� ������� T
    model_T->clear();

    //��������� ��������
    QStringList horizontalHeader1;
    for(int i=1;i<=N;i++) horizontalHeader1.append(QString::number(i));
    horizontalHeader1.append("e(v)"); horizontalHeader1.append(""); horizontalHeader1.append("");

    //��������� �����
    QStringList verticalHeader1;
    for(int i=1;i<=N;i++) verticalHeader1.append(QString::number(i));
    verticalHeader1.append(""); verticalHeader1.append("");


    model_T->setHorizontalHeaderLabels(horizontalHeader1);
    model_T->setVerticalHeaderLabels(verticalHeader1);


      for(int i=0;i<N;i++)
      {
        for(int j=0;j<N;j++)
        {
            item = new QStandardItem(QString::number(T[i][j]));
            model_T->setItem(i, j, item);
        }
        item = new QStandardItem(QString::number(e[i]));
        model_T->setItem(i, N, item);
      }

      item = new QStandardItem("D(G)=");
      model_T->setItem(N, N-1, item);
      item = new QStandardItem(QString::number(d));
      model_T->setItem(N, N, item);

      item = new QStandardItem("R(G)=");
      model_T->setItem(N+1, N-1, item);
      item = new QStandardItem(QString::number(r));
      model_T->setItem(N+1, N, item);


      for(int i=0;i<N;i++)
      {
          if(e[i]==r)
          item = new QStandardItem("Centr");
          model_T->setItem(i, N+1, item);
      }


    ui->T_table->setModel(model_T);
    ui->T_table->resizeRowsToContents();
    ui->T_table->resizeColumnsToContents();


    ui->comboBox_FROM->clear();
    ui->comboBox_TO->clear();
    for(int i=0;i<N;i++)
        ui->comboBox_FROM->insertItem(i,QString::number(i+1));
    for(int i=0;i<N;i++)
    {
        ui->comboBox_TO->insertItem(i,QString::number(i+1));
    }


    repaint();

}

void Widget::on_pushButton_PTY_clicked()
{
    //������ ��������
    ui->long_2->clear();
    ui->way->clear();
    int from = ui->comboBox_FROM->currentText().toInt();
    int to = ui->comboBox_TO->currentText().toInt();
    if(from==to)
        ui->way->insertPlainText("FROM==TO");
    else
    {
        int H_for_del[N][N];
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
            {
                H_for_del[i][j]=H[i][j];
            }
        int j=from-1;
        int way[N];
        way[0]=from;
        int k=0;
        int i=0;
            while(1)
            {
                if((Sm[to-1][from-1]==1)&&(!H[to-1][from-1]))//���� ��� ������ ����� ����� � ��� ����������� ����
                {
                    k++;
                    way[k]=to;
                     break;
                }
                if(i==N) break;
                if(i==from-1)
                {
                    k=0;
                }
                if(!H_for_del[i][j]) i++;

                else if(H_for_del[i][j])
                {
                    k++;
                    way[k]=H_for_del[i][j];
                    H_for_del[i][j]=0;
                    j=i;
                    i=0;
                    if (j==to-1)
                       {
                            k++;
                           way[k]=to;
                            break;
                       }

                 }

              }


        for(int i=0;i<k;i++)
        {
            ui->way->insertPlainText(QString::number(way[i])+"-->");
        }
        ui->way->insertPlainText(QString::number(way[k]));
        ui->long_2->insert(QString::number(k));
    }


}

void Widget::on_pushButton_2_clicked()
{
    QString n_str=ui->lineEdit->text();ui->textEdit_2->clear();
    int n = n_str.toInt(); //����� ����, �������� �� ����
    int kol=0;//���������� ���������
    if(n>0)
    {
        for(int from=1;from<=N;from++)
            for(int to=1;to<=N;to++)
            {
                //������ ��������
                if(from!=to)
                {
                    int H_for_del[N][N];
                    for(int i=0;i<N;i++)
                        for(int j=0;j<N;j++)
                        {
                            H_for_del[i][j]=H[i][j];
                        }
                    int j=from-1;
                    int way[N];
                    way[0]=from;
                    int k=0;
                    int i=0;
                        while(1)
                        {
                            if((Sm[to-1][from-1]==1)&&(!H[to-1][from-1]))//���� ��� ������ ����� ����� � ��� ����������� ����
                            {
                                k++;
                                way[k]=to;
                                 break;
                            }
                            if(i==N) break;
                            if(i==from-1)
                            {
                                k=0;
                            }
                            if(!H_for_del[i][j]) i++;

                            else if(H_for_del[i][j])
                            {
                                k++;
                                way[k]=H_for_del[i][j];
                                H_for_del[i][j]=0;
                                j=i;
                                i=0;
                                if (j==to-1)
                                   {
                                        k++;
                                       way[k]=to;
                                        break;
                                   }

                             }

                          }
                        if(k==n)
                        {
                            for(int i=0;i<k;i++)
                            {
                                ui->textEdit_2->insertPlainText(QString::number(way[i])+"-->");
                            }
                            ui->textEdit_2->insertPlainText(QString::number(way[k])+"\n");
                            kol++;
                       }
                }

            }
        ui->textEdit_2->insertPlainText(QString::number(kol)+"\n");

    }
    else
       ui->textEdit_2->insertPlainText("long<1\n");
}

 /* //������ ���������

           const float ostr = 0.25;// ������� �������
           float x = x_2 - x_1;
           float y = y_2 - y_1;
           float lons =  12;// ����� ���������
           float ugol = atan2(y, x);// ���� ������� �����
           QPolygon polygon;
           polygon << QPoint(x_2, y_2)
                   << QPoint(x_2 - lons * cos(ugol - ostr), y_2 - lons * sin(ugol - ostr))
                   << QPoint(x_2 - lons * cos(ugol + ostr), y_2 - lons * sin(ugol + ostr))
                      ;
          painter.setBrush(QBrush(Qt::red
                                   , Qt::SolidPattern));
           painter.drawPolygon(polygon, Qt::OddEvenFill );
           painter.setPen(QPen(Qt::blue, 2, Qt::SolidLine, Qt::FlatCap));
           painter.drawText(x_2- 30 * cos(ugol - ostr) ,y_2 - 30* sin(ugol - ostr) ,QString::number(S[from-1][to-1]));

    //���������� ������� H
    model_H->clear();


    //��������� ��������
    QStringList horizontalHeader_H;
    for(int i=1;i<=v;i++) horizontalHeader_H.append(QString::number(i));

    //��������� �����
    QStringList verticalHeader_H;
    for(int i=1;i<=v;i++) verticalHeader_H.append(QString::number(i));

    model_H->setHorizontalHeaderLabels(horizontalHeader_H);
    model_H->setVerticalHeaderLabels(verticalHeader_H);

    for(int i=0;i<v;i++)
      for(int j=0;j<v;j++)
      {
       item = new QStandardItem(QString::number(H[i][j]));
       model_H->setItem(i, j, item);
      }

    ui->H_table->setModel(model_H);
    ui->H_table->resizeRowsToContents();
    ui->H_table->resizeColumnsToContents();*/
