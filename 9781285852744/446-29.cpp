#include<iostream>

using namespace std;

//Function prototypes needed for the
//problem. Formal parameters that are
//pass by reference will change the value
//of the actual parameters.

int func(int, int);
void func2(int, int&);

int main(){
     int x,y;
     x = 6;
     cout<<"Enter a positive integer: ";
     cin>> y;
     cout <<endl;
     cout<<func(x,y)<<endl;
     y = y - x;
     cout<<x<<" "<<y<<endl;
     func2(x,y);
     cout<<x<<" "<<y<<endl;
     return 0;
}

int func(int x,int y){
    int z;
    z= x+y;
    y = x* z;
    return y;
}

//The value of the parameter int& y, will
//change in the calling function since
//it using pass by reference.
void func2(int x, int& y){
    int num1,num2;
    num1 = x+y;
    num2 = x*y;
    y = num1+num2;
    cout<<num1<<" "<<num2<<endl;
}