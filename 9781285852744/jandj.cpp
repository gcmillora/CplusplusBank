#include<iostream>

using namespace std;

//A function to compute for the bill based on the
//specifications of the problem. Takes 3 variables as its
//parameters, the rate per hour, total time of consultation,
//and the income.
double computeBill(double rate,double time,double income){
    if(income<=25000){
        if(time>30)
            return rate * 0.4 * ((time-30)/60);
        else
            return 0;
    }
    else{
        if(time<=20){
            return 0;
        }
        else{
            return rate * 0.7* ((time-20)/60);
        }
    }
}
int main(){
    //Declare variables of type double to store the input
    //from  the user.
    double rate, time, amount,income;
    cout<<"Please input your income: ";
    cin>>income;
    cout<<"Please input the hourly rate: ";
    cin>>rate;
    cout<<"Please input the consulting time (mins): ";
    cin>>time;
    
    //Compute the total billing amount by calling the
    //function computeBill(double,double,double) and pass
    //the appropriate arguments.
    amount = computeBill(rate,time,income);
    cout<<"Billing Amount: "<<amount;
}