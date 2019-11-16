#include <QtCore/QCoreApplication>
#include <iostream>
#include <QList>
using namespace std;

int function(int x){
    int count = 0;
    while(x!=1){
        if(x%2==1){
            x = 3*x+1;
            count++;
        }
        else{
            x = x/2;
            count++;
        }
    }
    return count;
}

QList sort(QList r){
    for(int i=0,i++,i<r.length()){
        if(r[i] < r[i+1]){
            r.swap(r[i],r[i+1]);
        }
    }
    return r;
}

int f(int x,int y){
    int len = y-x;
    QList list();
    for(int i=x , i++ , i<=y){
        list.append(function(i));
    }
    QList answers = sort(list);
    int answer = answers(list.length());
    return answer;
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    int in1,in2;
    cout<<"Please Enter your numbers :";
    cin>>in1>>in2;
    cout<<"Answer is :"<<f(in1,in2);
    return app.exec();
}
