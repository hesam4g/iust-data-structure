#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLayout>
#include <QDir>
#include <QString>
#include<QEvent>
#include <QInputDialog>
#include <QLabel>
#include <math.h>"
#include<QPalette>
#include <RB_tree.h>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{

    //forDraw=new QWidget();

    l =new QLabel();
    l1 =new QLabel();
    about = new QPushButton("About");
    help = new QPushButton("Help");
    exit = new QPushButton("Exit");
    insert = new QPushButton("Insert");
    delet = new QPushButton("Delet");
    in = new QPushButton("In order");
    prev = new QPushButton("Pre order");
    next = new QPushButton("Post order");
    s = new QInputDialog();
    q=s;
    s1 = new QInputDialog();
    q1=s1;
    lable=l;
    lable1=l1;
    //QVBoxLayout *re = new QVBoxLayout(o1);
    l2 =new QLabel();
    l3 =new QLabel();
    //re->addWidget(l2);
    //o1->setLayout(re);

    l2->setText("Befor");
    l3->setText("After");
    l-> setStyleSheet("background-color: white");
    l1-> setStyleSheet("background-color: white");
    this->resize(1200,700);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    l->resize(600,300);
    l1->resize(600,300);
    QHBoxLayout *row1 = new QHBoxLayout();
    row1->addWidget(insert);
    row1->addWidget(delet);
    row1->addWidget(in);
    row1->addWidget(prev);
    row1->addWidget(next);
    row1->addWidget(help);
    row1->addWidget(about);
    row1->addWidget(exit);
    l2->resize(600,10);
    l2->resize(600,10);
    QHBoxLayout *row3 = new QHBoxLayout();
    l->setText("Befor");
    l1->setText("Aefor");
    QHBoxLayout *row2 = new QHBoxLayout();
    row2->addWidget(l);
    row2->addWidget(l1);
    mainLayout->addLayout(row1);

    mainLayout->addLayout(row2);


    connect(insert,SIGNAL(clicked()),this,SLOT(add()));
    connect(delet,SIGNAL(clicked()),this,SLOT(add1()));
    connect(exit,SIGNAL(clicked()),this,SLOT(close()));
    connect(in,SIGNAL(clicked()),this,SLOT(ino()));
     connect(next,SIGNAL(clicked()),this,SLOT(post()));
      connect(prev,SIGNAL(clicked()),this,SLOT(preo()));
      connect(help,SIGNAL(clicked()),this,SLOT(hel()));
       connect(about,SIGNAL(clicked()),this,SLOT(abo()));



}
QString space(int n)
{
    int o=pow(2,n);
    int v= 200/o;
    QString b="";
    for(int i=0 ;i<v;i++)
        b = b +"&nbsp;";
    return b;
}
void MainWindow::draw(int *list,int * color, int n,int k)
{

    QString p="<font size=\"1\" color=\"black\">";
    int count = 0;
    int g;
    int j=1;
    int t=1;
    if(n>0){
    while(count< n)
    {
        p = p + space(j);
        for(int i=0;i<t;i++)
            {
                if(count == n)
                    break;
            g=list[count];
            QString s = QString::number(g, 10);
            if(g==-1)
                p = p + "&nbsp;" + space(j-1) ;
            else{
            if(color[count] == 0)
                p = p +  s + space(j-1) ;
            else
                p = p +"</font><font size=\"1\" color=\"red\">" + s + space(j-1) + "</font><font size=\"1\" color=\"black\">";
            }
            count++;
            }
        t = t * 2;
        j++;
        p = p + "<br/><br/><br/><br/><br/>" ;




    }
    p = p +"</font>";
    if(k==1)
        lable->setText(p);
    else
        lable1->setText(p);
    }


}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::add(){

    int * o;
    int * y;
    int p = t.heigh;
    o = new int[p];
    y = new int[p];
    for(int i=0 ;i<p ; i++)
        {
            o[i] = t.get_one_color(i);
            y[i] = t.get_one_value(i);
        }

    draw(y,o,p,1);
    delete [] o ;
    delete [] y ;
    int a  = q->getInt(this, tr("QInputDialog::getInteger()"),tr("value of node"));
    if(a>0){
    t.insert(a);
    int * o1;
    int * y1;
    int p1 = t.heigh;
    o1 = new int[p1];
    y1 = new int[p1];
    for(int i=0 ;i<p1 ; i++)
        {
            o1[i] = t.get_one_color(i);
            y1[i] = t.get_one_value(i);
        }

    draw(y1,o1,p1,2);
    delete [] o1 ;
    delete [] y1 ;

}

}
void MainWindow::add1(){

    int * o;
    int * y;
    int p = t.heigh;
    o = new int[p];
    y = new int[p];
    for(int i=0 ;i<p ; i++)
        {
            o[i] = t.get_one_color(i);
            y[i] = t.get_one_value(i);
        }

    draw(y,o,p,1);
    int  b  = q1->getInt(this, tr("QInputDialog::getInteger()"),tr("value of key"));
    if(b>0){
    t.delet(t.get_addres(b));
    int * o1;
    int * y1;
    int p1 = t.heigh;
    o1 = new int[p1];
    y1 = new int[p1];
    for(int i=0 ;i<p1 ; i++)
        {
            o1[i] = t.get_one_color(i);
            y1[i] = t.get_one_value(i);
        }

    draw(y1,o1,p1,2);
    }

}
void MainWindow::ino(){

    //pre();
    lable->setText("In order is : "+t.inorder);
   // lable->setText(QString::number(t.root->left->value,10));

}
void MainWindow::preo(){

    //pre();
    lable->setText("Pre order is : "+t.preorder);
   // lable->setText(QString::number(t.root->left->value,10));

}
void MainWindow::post(){

    //pre();
    lable->setText("Post order is: "+t.postorder);
   // lable->setText(QString::number(t.root->left->value,10));

}
void MainWindow::abo()
{
lable->setText("This is Red/Black Tree \nProgramer :\n           Mohamad sadegh Boorooni\nWith Student Number\n            89521267");
}
void MainWindow::hel()
{

lable->setText("for inset node you just press insert and write your value of nod\nfor delete press delete and enter value of your node \nfor Pre or in or post order just press button of them\njust one thing your number have to be greater than 0 ");
}


