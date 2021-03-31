#include<iostream>

using namespace std;

void func_1(int&,int&,int&);

int main(){
    int num1,num2,num3;
    num1 = 1;
    num2 = 2;
    num3 = 3;
    func_1(num1,num2,num3);
    cout<<num1<<", "<<num2<<", "<<num3<<endl;
    func_1(num2,num1,num3);
    cout<<num1<<", "<<num2<<", "<<num3<<endl;
    func_1(num3,num2,num1);
    cout<<num1<<", "<<num2<<", "<<num3<<endl;
    func_1(num2,num3,num1);
    cout<<num1<<", "<<num2<<", "<<num3<<endl;
    return 0;
}

void func_1(int& num1,int& num2, int& num3){
    int temp;
    num3 = num1 *num2+2;
    temp = num3;    
    if(num2==0){
        num1=num3/(num2+1);
    }
    num1 = num1 + num3 - num2;
    num3 = num2 * temp;
}