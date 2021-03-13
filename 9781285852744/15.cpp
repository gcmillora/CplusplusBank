#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

//Function prototypes as specified by the problem.
void func1();
void func2(int& num1, int& num2, double& num3);

int main(){
    int num1, num2;
    double num3;
    int choice = 0;
    cout<<fixed <<showpoint<< setprecision(2);
    do{
        func1();
        cin>>choice;
        cout<<endl;
        if(choice==1){
            func2(num1,num2,num3);
            cout<<num1<<", "<<num2<<", "<<num3<<endl;  
        }
    }
    while(choice!=99);
    return 0;
}

void func1(){
    cout<<"To run the program, enter 1."<<endl;
    cout<<"To exit the program, enter 99."<<endl;
    cout<<"Enter 1 or 99: ";
}

//Use referencing to be able to change the value of
//the variables from the main function since function
//func2 is a non-returning function. Make sure to test
//if the values changed after manipulation.
void func2(int& num1,int& num2,double& num3){
    cout<<"Please input first number: ";
    cin>> num1;
    cout<<"Please input second number: ";
    cin>>num2;
    if(num1&&num2){
        if(num1>=num2)
            num3 = pow(num1,num2);
        else
            num3 = pow(num2,num1);
    }
    else if(num1&&num2==0)
        num3 = sqrt(abs(num1));
    
    else if(num1==0&&num2)
        num3 = sqrt(abs(num2));
    else
        num3 = 0;
}