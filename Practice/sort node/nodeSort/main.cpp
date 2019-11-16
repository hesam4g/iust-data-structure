#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

class leaf{
public:
    int times;
    char content;
    leaf();
    leaf(char x,int n);
};

leaf::leaf(){
    times = 0;
}

leaf::leaf(char x, int n){
    content = x;
    times = n;
}

void quickSort(leaf arr[], int left, int right)
{
      int i = left, j = right;
      leaf tmp;
      leaf pivot = arr[(left + right) / 2];

      while (i <= j) {
            while (arr[i].times < pivot.times)
                  i++;
            while (arr[j].times > pivot.times)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      }
}



int main()
{
    ifstream inf("info.txt");
    int n;
    inf>>n;
    leaf leafes[n];
    char x;
    int t;
    for(int i=0;i<n;i++)
    {
        inf>>x>>t;
        leafes[i]=leaf(x,t);

    }

    quickSort(leafes,0,n);
    for(int j=0;j<n;j++){
        cout<<leafes[j].times<<endl;
    }
    getch();
    return 0;
}
