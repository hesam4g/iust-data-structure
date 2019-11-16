#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;


void make2file(int count,int lines)
{
    ofstream tmp1("tmp1.txt");
    ofstream tmp2("tmp2.txt");
    ifstream inFile("out.txt");
    int inNum;
    int counter=0;
    if(lines%2!=0)
        lines++;
    for(int q=0;q<lines;q++){
        while(counter<count){
            if(inFile>>inNum){
                tmp1<<inNum<<" ";
                counter++;
            }
            else
                return;
        }
        if(counter==count)
            tmp1<<endl;
        counter = 0;
        while(counter<count){
            if(inFile>>inNum){
                tmp2<<inNum<<" ";
                counter++;
            }
            else
                return;
        }
        if(counter==count)
            tmp2<<endl;
        counter=0;

    }
    tmp1.close();
    tmp2.close();
    inFile.close();
}


void merge2file(int count,int lines)
{
    ifstream tmp1("tmp1.txt");
    ifstream tmp2("tmp2.txt");
    ofstream outFile("out.txt");
    int i,j;
    tmp1>>i;
    tmp2>>j;

    for(int k=0;k<lines;k++){
        int firstCounter=0;
        int secondCounter=0;
        while(firstCounter+secondCounter<2*count){
            if(firstCounter!=count && secondCounter!=count){
                if(i<=j){
                    outFile<<i<<" ";
                    tmp1>>i;
                    firstCounter++;
                }
                if(i>j){
                    outFile<<j<<" ";
                    if(tmp2>>j)
                        secondCounter++;
                    else
                        secondCounter = count;
                }
            }
            if(firstCounter==count && secondCounter!=count){
                outFile<<j<<" ";
                if(tmp2>>j)
                    secondCounter++;
                else
                    secondCounter = count;
            }
            if(firstCounter!=count && secondCounter==count){
                outFile<<i<<" ";
                tmp1>>i;
                firstCounter++;
            }
        }
        outFile<<endl;
    }

    tmp1.close();
    tmp2.close();
    outFile.close();
}


void quickSort(int arr[], int left, int right)
{
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];

      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}


void arrange(int a){
    ifstream temperory("out.txt");
    ofstream final("finalOutPut.txt");
    int l;
    for(int i=0;i<a;i++){
        for(int j=0;j<100;j++)
            if(temperory>>l)
                final<<l<<" ";
    final<<endl;
    }
    final.close();
    temperory.close();
}


int midSort()
{
    ifstream infile("in.txt");
    ofstream outfile("out.txt");
    int i,numOfline=0;
    while(infile>>i){
        int p[100];
        for(int j=0;j<100;j++){
            p[j] = i;
            if(!infile>>i)
                p[j]=0;
            infile>>i;
        }
        quickSort(p,0,100);
        for(int g=0;g<100;g++){
            outfile<<p[g]<<" ";
        }
        outfile<<endl;
        numOfline++;
    }
    infile.close();
    outfile.close();
    return numOfline;
}


int log(int x){
    int y=1;
    int n=0;
    while(y<x){
        y*=2;
        n++;
    }
    return n;
}



int power(int x,int y){
    int z=1;
    for(int i=0;i<y;i++)
        z*=x;
    return z;
}

int main()
{
    int a=midSort();
    int b=a;
    cout<<"soreted number will save in finaOutPut.txt"<<endl;
    cout<<"finalOutPut has "<<a<<" lines"<<endl;

    int c= log(a);
    int d=100;

    for(int i=0;i<c;i++){
        make2file(d,a);
        if(a%2==1)
            a++;
        merge2file(d,a/2);
        d*=2;
        if(a%2==1)
            a++;
    }

    arrange(b);
    cout<<"Finished!!";
    getchar();
    return 0;
}
