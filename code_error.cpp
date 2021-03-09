#include<iostream>

using namespace std;

int main(){
    int num1,num2;
    bool found;
    cout<<"Enter two integers: ";
    cin>> num1>>num2;
    cout<<endl;
    if(num1>=num2&&num2>0){
        switch(num1%num2){
            case 1:
                found =(num1/num2)>=6;
                break;
            case 2:
                num1=num2/2;
                break;
            case 3:
                num1=num2/3;
                break;
            default:
                num2 = num1*num2;
        }
    }
    cout<<num1<<" "<<num2;
}