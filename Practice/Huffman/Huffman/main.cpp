#include <iostream>
#include "hoffman.h"

using namespace std;

int main(){
    Hoffman myHoff;
    myHoff.decode("1110");
    myHoff.decode("111100");
    myHoff.decode("100");
    int a;
    cin>>a;
    return 0;
}
