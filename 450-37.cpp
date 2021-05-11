#include<iostream>

using namespace std;

void funcDefaultParam(double x=7.3,int y=4,string z ="*"){
    cout<<x<<" "<<y<<" "<<z<<endl;
}

int main(){
    funcDefaultParam();
    funcDefaultParam(2.8);
    funcDefaultParam(3.2,0,"h");
    funcDefaultParam(9.2,"*");
    funcDefaultParam(7,3);
}