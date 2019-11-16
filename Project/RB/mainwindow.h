#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QString>
#include <RB_tree.h>
#include <QInputDialog>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    RB_tree t;
    QLabel *lable;
    QLabel *lable1;
    QInputDialog *q ;
    QInputDialog *q1 ;
    void draw (int *list,int * color, int n ,int k);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QPushButton *about;
    QPushButton *help;
    QPushButton *exit;
    QPushButton *insert;
    QPushButton *delet;
    QPushButton *in;
    QPushButton *prev;
    QPushButton *next;
    QInputDialog *s;
    QInputDialog *s1;
    QLabel *l ;
    QLabel *l1 ;
    QLabel *l2 ;
    QLabel *l3 ;
    QWidget *forDraw;
    QMainWindow *h1;
    QMainWindow *o1;


private slots:
    void add();
    void add1();
    void preo();
    void ino();
    void post();
    void hel();
    void abo();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
