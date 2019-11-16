#include <iostream>
#include <conio.h>
using namespace std;

void foo(double val,int i )
{
    if(val != 0.0 )
    {
        cout<<val<<endl;
        cout<<i<<endl;
        i++;
        foo(val/2.0,i);
    }

}

int main()
{
    int c=1;
    foo(1.0,c);
	getch();
    return 0;
}
