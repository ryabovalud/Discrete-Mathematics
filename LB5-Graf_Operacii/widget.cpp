#include "widget.h"
#include "ui_widget.h"
#include "math.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

int N1=0, N2=0, N3=0, N4=0;//���������� ������
int **S1, **S2, **S3, **S4;//������� ���������
int *V1,*V2;//������� ������


//������ �����
void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);


  QPainter painter(this);
  painter.begin(this);
  painter.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));

  //������ ���� 1
  float x1[N1],y1[N1];//���������� ����� - ������ i-�� �������
  float alpha1 = 2*M_PI/N1;
  int x01 = 919/4+10, y01 = 614/4, R1=100,//������ �����
                                        r1= 10;

     for(int i = 1; i<=N1 ; i++) //������ N ������ �������
     {
         if(V1[i-1])//���� ��p���� �� �������
         {
             x1[i]= x01+R1*cos(i*alpha1);
             y1[i]= y01+R1*sin(i*alpha1);

             QPoint center1(x1[i],y1[i]);
             painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap));
             painter.drawEllipse(center1,r1,r1);
             painter.drawText(x1[i]-r1/2,y1[i]+r1/2,QString::number(i));
         }
     }
     for (int i =1;i<=N1;i++)
     {
         for (int j=1;j<=N1;j++)
            if(S1[i-1][j-1]==1)
            {
                //������ �����
                painter.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap));
                float x_1,x_2,y_1,y_2;
                x_1= x1[i]+r1*cos(j*alpha1);y_1= y1[i]+r1*sin(j*alpha1);
                x_2= x1[j]+r1*cos(i*alpha1);y_2= y1[j]+r1*sin(i*alpha1);
                  painter.drawLine(x_1, y_1, x_2, y_2);
            }
      }

     //������ ���� 2

     float x2[N2],y2[N2];//���������� ����� - ������ i-�� �������
     float alpha2 = 2*M_PI/N2;
     int x02 = 919/4+ 240, y02 = 614/4 , R2=100,//������ �����
                                           r2= 10;

        for(int i = 1; i<=N2 ; i++) //������ N ������ �������
        {
             x2[i]= x02+R2*cos(i*alpha2);

             y2[i]= y02+R2*sin(i*alpha2);
          QPoint center2(x2[i],y2[i]);
           painter.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));
            painter.drawEllipse(center2,r2,r2);
            painter.drawText(x2[i]-r2/2,y2[i]+r2/2,QString::number(i));
        }
        for (int i =1;i<=N2;i++)
        {
            for (int j=1;j<=N2;j++)
               if(S2[i-1][j-1]==1)
               {
                   //������ �����
                   painter.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap));
                   float x_1,x_2,y_1,y_2;
                   x_1= x2[i]+r2*cos(j*alpha2);y_1= y2[i]+r2*sin(j*alpha2);
                   x_2= x2[j]+r2*cos(i*alpha2);y_2= y2[j]+r2*sin(i*alpha2);
                     painter.drawLine(x_1, y_1, x_2, y_2);
               }
         }

        //������ ���� 3 - ����������� ������
        float x3[N3],y3[N3];//���������� ����� - ������ i-�� �������
        float alpha3 = 2*M_PI/N3;
        int x03 = 919/4, y03 = 614/4 + 250, R3=100,//������ �����
                                              r3= 10;

        for(int i = 1; i<=N3 ; i++) //������ N ������ �������
        {
            x3[i]= x03+R3*cos(i*alpha3);
            y3[i]= y03+R3*sin(i*alpha3);

            QPoint center3(x3[i],y3[i]);
            painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap));
            painter.drawEllipse(center3,r3,r3);
            painter.drawText(x3[i]-r3/2,y3[i]+r3/2,QString::number(i));
        }
        for (int i =1;i<=N3;i++)
        {
            for (int j=1;j<=N3;j++)
               if(S3[i-1][j-1]==1)
               {
                   //������ �����
                   painter.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));
                   float x_1,x_2,y_1,y_2;
                   x_1= x3[i]+r3*cos(j*alpha3);y_1= y3[i]+r3*sin(j*alpha3);
                   x_2= x3[j]+r3*cos(i*alpha3);y_2= y3[j]+r3*sin(i*alpha3);
                   painter.drawLine(x_1, y_1, x_2, y_2);
               }
         }

    //������ ���� 4 - ���������� ������
    /*if(N4)//���� ����������
    {
        float x4[N4+1],y4[N4+1];//���������� ����� - ������ i-�� �������
        float alpha4_1 = 2*M_PI/N1, alpha4_2 = 2*M_PI/N2;
        int x04_1 = 919/4 + 150, y04_1 = 614/4 + 250, R4=100,//������ �����
                                              r4= 10,
                x04_2 = 919/4 + 400, y04_2 = 614/4 + 250;

           for(int i = 1; i<=N1 ; i++) //������ N1 ������ �������
           {
               x4[i]= x04_1+R4*cos(i*alpha4_1);
               y4[i]= y04_1+R4*sin(i*alpha4_1);

               QPoint center4(x4[i],y4[i]);
               painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap));
               painter.drawEllipse(center4,r4,r4);
               painter.drawText(x4[i]-r4/2,y4[i]+r4/2,QString::number(i));
           }
           for(int i = N1+1; i<=N4 ; i++) //������ N2 ������ �������
           {
               x4[i]= x04_2+R4*cos((i-N1)*alpha4_2);
               y4[i]= y04_2+R4*sin((i-N1)*alpha4_2);

               QPoint center4(x4[i],y4[i]);
               painter.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));
               painter.drawEllipse(center4,r4,r4);
               painter.drawText(x4[i]-r4/2,y4[i]+r4/2,QString::number(i-N1));
           }

           //������������� ������ ����
           for (int i =1;i<=N1;i++)
           {
               for (int j=1;j<=N1;j++)
                  if(S4[i-1][j-1]==1)
                  {
                      //������ �����
                      painter.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));
                      float x_1,x_2,y_1,y_2;
                      {
                          x_1= x4[i]+r4*cos(j*alpha4_1);y_1= y4[i]+r4*sin(j*alpha4_1);
                          x_2= x4[j]+r4*cos(i*alpha4_1);y_2= y4[j]+r4*sin(i*alpha4_1);
                          painter.drawLine(x_1, y_1, x_2, y_2);
                      }
                    }
            }

           //������������� ������ ����
           for (int i =N1+1;i<=N4;i++)
           {
               for (int j=N1+1;j<=N4;j++)
                  if(S4[i-1][j-1]==1)
                  {
                      //������ �����
                      painter.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap));
                      float x_1,x_2,y_1,y_2;
                      {
                          x_1= x4[i]+r4*cos((j-N1)*alpha4_2);y_1= y4[i]+r4*sin((j-N1)*alpha4_2);
                          x_2= x4[j]+r4*cos((i-N1)*alpha4_2);y_2= y4[j]+r4*sin((i-N1)*alpha4_2);
                          painter.drawLine(x_1, y_1, x_2, y_2);
                      }
                    }
            }

           //��������� ����� ���� � ������
           for (int i =1;i<=N1;i++)
           {
               for (int j=N1+1;j<=N4;j++)
                  if(S4[i-1][j-1]==1)
                  {
                      //������ �����
                      painter.setPen(QPen(Qt::blue, 2, Qt::SolidLine, Qt::FlatCap));
                      float x_1,x_2,y_1,y_2;
                      {
                          x_1= x4[i]+r4*cos(4*alpha4_2);y_1= y4[i]+r4*sin(4*alpha4_2);
                          x_2= x4[j]+r4*cos(1*alpha4_2);y_2= y4[j]+r4*sin(1*alpha4_2);
                          painter.drawLine(x_1, y_1, x_2, y_2);
                      }
                    }
            }
    }*/

        //���������� ������ 4
        float x4[N4],y4[N4];//���������� ����� - ������ i-�� �������
        float alpha4 = 2*M_PI/N4;
        int x04 = 919/4+350, y04 = 614/4+250, R4=100,//������ �����
                                              r4= 10;

           for(int i = 1; i<=N4 ; i++) //������ N ������ �������
           {
               //if(V1[i-1])//���� ��p���� �� �������
               {
                   x4[i]= x04+R4*cos(i*alpha4);
                   y4[i]= y04+R4*sin(i*alpha4);

                   QPoint center4(x4[i],y4[i]);
                   painter.setPen(QPen(Qt::blue, 2, Qt::SolidLine, Qt::FlatCap));
                   painter.drawEllipse(center4,r4,r4);
                   painter.drawText(x4[i]-r4/2,y4[i]+r4/2,QString::number(i));
               }
           }
           for (int i =1;i<=N4;i++)
           {
               for (int j=1;j<=N4;j++)
                  if(S4[i-1][j-1]==1)
                  {
                      //������ �����
                      painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap));
                      float x_1,x_2,y_1,y_2;
                      x_1= x4[i]+r4*cos(j*alpha4);y_1= y4[i]+r1*sin(j*alpha4);
                      x_2= x4[j]+r4*cos(i*alpha4);y_2= y4[j]+r1*sin(i*alpha4);
                        painter.drawLine(x_1, y_1, x_2, y_2);
                  }
            }

}


//C�������� ����� �� �����
void Widget::on_pushButton_clicked()
{
    //���� 1
    //���������e ���������� �� �����
    QFile file("C:\\Users\\brrri\\OneDrive\\Study\\Alg Diskr Math\\LB\\LB5-Graf_Operacii\\graf1.txt"); // ������� ������ ������ QFile
    if (file.open(QIODevice::ReadOnly)) // ���������, �������� �� ������� ��� ���� ��� ������
        {
            QTextStream in(&file);
            in >> N1; // ��������� N - ���������� ������
            //���������� ������ ��� ������� ���������
            S1=new int* [N1];
              for (int i=0;i<N1;i++)
                 S1[i]=new int[N1];
            for (int i=0;i<N1;i++)
                for(int j=0;j<N1;j++)
                {
                    in>>S1[i][j];
                }
             file.close();
        }

    V1=new int [N1];
    for (int i=0;i<N1;i++)
        V1[i]=1;

    //��������� ���������
    ui->comboBox->clear();
    for(int i=0;i<N1;i++)
        ui->comboBox->insertItem(i,QString::number(i+1));
    ui->comboBox_2->clear();
    for(int i=0;i<N1;i++)
        ui->comboBox_2->insertItem(i,QString::number(i+1));
    ui->comboBox_3->clear();
    for(int i=0;i<N1;i++)
        ui->comboBox_3->insertItem(i,QString::number(i+1));


    //���� 2
    //���������e ���������� �� �����
    QFile file2("C:\\Users\\brrri\\OneDrive\\Study\\Alg Diskr Math\\LB\\LB5-Graf_Operacii\\graf2.txt"); // ������� ������ ������ QFile
    if (file2.open(QIODevice::ReadOnly)) // ���������, �������� �� ������� ��� ���� ��� ������
        {
            QTextStream in(&file2);
            in >> N2; // ��������� N - ���������� ������
            //���������� ������ ��� ������� ���������
            S2=new int* [N2];
              for (int i=0;i<N2;i++)
                 S2[i]=new int[N2];
            for (int i=0;i<N2;i++)
                for(int j=0;j<N2;j++)
                {
                    in>>S2[i][j];
                }
             file2.close();
        }
    repaint();
}




//�������� ���� 1
void Widget::on_obr_1_clicked()
{
    for (int i=0;i<N1;i++)
        for(int j=0;j<N1;j++)
        {
            if(S1[i][j]==1) S1[i][j]=0;
            else if(S1[i][j]==0) S1[i][j]=1;
        }
    repaint();
}

//�������� ���� 2
void Widget::on_obr_2_clicked()
{
    for (int i=0;i<N2;i++)
        for(int j=0;j<N2;j++)
        {
            if(S2[i][j]==1) S2[i][j]=0;
            else if(S2[i][j]==0) S2[i][j]=1;
        }
    repaint();
}

//������� �������
void Widget::on_del_1_clicked()
{
    int del1 = ui->comboBox->currentText().toInt();
    V1[del1-1]=0;
    for (int j=0;j<N1;j++)
            {
                S1[del1-1][j]=-1;
                S1[j][del1-1]=-1;
            }

    //��������� ���������
    ui->comboBox_2->clear();
    for(int i=0;i<N1;i++)
        if(V1[i])
            ui->comboBox_2->insertItem(i,QString::number(i+1));
    ui->comboBox_3->clear();
    for(int i=0;i<N1;i++)
        if(V1[i])
            ui->comboBox_3->insertItem(i,QString::number(i+1));
    repaint();
}


//������� �����
void Widget::on_pushButton_2_clicked()
{

    int v1 = ui->comboBox_2->currentText().toInt();
    int v2 = ui->comboBox_3->currentText().toInt();
    S1[v1-1][v2-1]=0;
    S1[v2-1][v1-1]=0;

    repaint();
}

//��������� �����
void Widget::on_pushButton_3_clicked()
{
    int v1 = ui->comboBox_2->currentText().toInt();
    int v2 = ui->comboBox_3->currentText().toInt();
    S1[v1-1][v2-1]=1;
    S1[v2-1][v1-1]=1;

    repaint();
}

//��������� �������
void Widget::on_pushButton_4_clicked()
{
    int del1 = ui->comboBox->currentText().toInt();
    if(V1[del1-1]==0)
    {
        V1[del1-1]=1;
        for (int j=0;j<N1;j++)
                {
                    S1[del1-1][j]=0;
                    S1[j][del1-1]=0;
                }
    }
    else
    {
        int S[N1][N1],V[N1];

        //��������� �������� ������
        for (int i=0;i<N1;i++)
        {
            for(int j=0;j<N1;j++)
            {
                S[i][j]=S1[i][j];//������� ���������
            }
            V[i]=V1[i];//� �� �������� �������
        }

        N1++;//��������� ���������� ������ �� 1

        S1=new int* [N1];
          for (int i=0;i<N1;i++)
             S1[i]=new int[N1];

        //�������� ������
        for (int i=0;i<N1;i++)
        {
            for(int j=0;j<N1;j++)
            {
                S1[i][j]=0;//������� ���������
            }
            V1[i]=0;//� �� �������� �������
        }

        //�������������� ������
        for (int i=0;i<N1-1;i++)
        {
            for(int j=0;j<N1-1;j++)
            {
                S1[i][j]=S[i][j];//������� ���������
            }
            V1[i]=V[i];//� �� �������� �������
        }
        V1[N1-1]=1;

    }




    //��������� ���������
    ui->comboBox_2->clear();
    for(int i=0;i<N1;i++)
        if(V1[i])
            ui->comboBox_2->insertItem(i,QString::number(i+1));
    ui->comboBox_3->clear();
    for(int i=0;i<N1;i++)
        if(V1[i])
            ui->comboBox_3->insertItem(i,QString::number(i+1));
    repaint();
}

//���������� �����
void Widget::on_pushButton_5_clicked()
{
    if(N1>N2)
    {
        //���������� ������ ��� ������� ���������
        N3=N1;
        S3=new int* [N3];
          for (int i=0;i<N3;i++)
             S3[i]=new int[N3];
        for (int i=0;i<N1;i++)
            for(int j=0;j<N1;j++)
            {
                S3[i][j]=S1[i][j];
            }
        for (int i=0;i<N2;i++)
            for(int j=0;j<N2;j++)
            {
                if(S2[i][j])
                    S3[i][j]=S2[i][j];
            }
    }
    else
    {
        //���������� ������ ��� ������� ���������
        N3=N2;
        S3=new int* [N3];
          for (int i=0;i<N3;i++)
             S3[i]=new int[N3];
        for (int i=0;i<N2;i++)
            for(int j=0;j<N2;j++)
            {
                S3[i][j]=S2[i][j];
            }
        for (int i=0;i<N1;i++)
            for(int j=0;j<N1;j++)
            {
                if(S1[i][j])
                    S3[i][j]=S1[i][j];
            }
    }
    repaint();
}

//���������� ������
void Widget::on_pushButton_6_clicked()
{

    /*N4=N1+N2;//���������� ������
    //����� ��� ������� ���������
    S4=new int* [N4];
    for (int i=0;i<N4;i++)
       S4[i]=new int[N4];
    //���������� ��� ������� ���������
    for (int i=0;i<N4;i++)
       for(int j=0;j<N4;j++)
       {
            S4[i][j]=1;
       }
    //����� ��������� ��� �����
    for (int i=0;i<N1;i++)
       for(int j=0;j<N1;j++)
       {
            S4[i][j]=S1[i][j];
       }
    for (int i=N1;i<N4;i++)
       for(int j=N1;j<N4;j++)
       {
            S4[i][j]=S2[i-N1][j-N1];
       }
    repaint();*/

    if(N1>N2) N4=N1;
    else N4=N2;
    S4=new int* [N4];
    for (int i=0;i<N4;i++)
       S4[i]=new int[N4];
    //��� ������� ���������
    for (int i=0;i<N4;i++)
       for(int j=0;j<N4;j++)
       {
            S4[i][j]=1;
       }
    repaint();
}
