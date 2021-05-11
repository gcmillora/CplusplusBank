#include<iostream>

namespace aaa{
    const int X =0;
    double y;
}
using namespace std;

int main(){
    aaa::y = 34.50;
    cout<< "X = " << aaa::X << ", y = "<< aaa::y
        <<endl;
    return 0;
}