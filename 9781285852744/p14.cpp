#include<iostream>

using namespace std;

//Function definitions specified from a to g.
//Some of the functions use pointers and references.
//This is to change the value of the integer from the
//main function without returning any value from the
//functions below.

void initialize(int& x, int& y, char& z){
    x = 0;
    y = 0;
    z = ' ';
}
void getHoursRate(double& rate, double& hours){
    cout<<"Please input the rate per hour: ";
    cin>>rate;
    cout<<"Please input the hours worked: ";
    cin>>hours;
}

double payCheck(double rate,double hours){
    if(hours>40)
        return 40*rate + (hours-40)*(rate*1.5);
    else
        return hours*rate;
}

void printCheck(double rate,double hours){
    cout<<"Hours worked: "<<hours<<endl;
    cout<<"Rate per hour: "<< rate<<endl;
    cout<<"Salary: "<<payCheck(rate,hours)<<endl;
}

void funcOne(int& x, int& y){
    int number;
    cout<<"Please input a number: ";
    cin>> number;
    x = 2 * x + y - number;
}

void nextChar(char& z){
    z+=1;
}

int main(){
    int x, y;
    char z;
    double rate,hours;
    double amount;
    initialize(x,y,z);
    cout<<"Initialized values of x,y,z : "<<x<<" "<<y<<" "<<z<<endl;
    getHoursRate(rate,hours);
    printCheck(rate,hours);
    funcOne(x,y);
    cout<<"New value of x: "<<x<<endl;
    z = 'a';
    nextChar(z);
    cout<<"New value of z: "<<z<<endl;
    return 0;
}