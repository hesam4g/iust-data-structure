#include <QtCore/QCoreApplication>
#include <iostream>

using namespace std;

void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];

      /* partition */
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

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int ls[]={32,24,65,24,67,24,88,7,6,54,34,54,32,67,89,6,5,33,45,6,43,45,23,16,90,23,56,29,8,5};
    for(int i=0;i<30;i++)
        cout<<ls[i]<<"  ";
    cout<<endl<<endl;
    quickSort(ls,0,30);
    for(int i=0;i<30;i++)
        cout<<ls[i]<<"  ";
    cout<<endl<<endl;

    return a.exec();
}
