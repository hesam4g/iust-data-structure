#include <QtGui/QApplication>
#include "mainwindow.h"
#include <math.h>
#include <RB_tree.h>
#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(1200,700);
    RB_tree tt;

    int c[32];
    int b[32];
    for(int i=0 ; i<31 ;i++)
        {
            c[i]=i%2;
            b[i]=i;
        }
  tt.insert(2);
    tt.insert(1);
    tt.insert(3);
    tt.insert(4);
    tt.insert(5);

    tt.insert(7);
    tt.insert(6);
    tt.delet(tt.get_addres(3));
    int * o;
    int * y;
    int p = tt.heigh;
    o = new int[p];
    y = new int[p];
    for(int i=0 ;i<p ; i++)
        {
            o[i] = tt.get_one_color(i);
            y[i] = tt.get_one_value(i);
        }

    //w.draw(y,o,p);


    w.show();
    return a.exec();
}
