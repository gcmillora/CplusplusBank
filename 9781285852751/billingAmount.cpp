#include<iostream>

using namespace std;

int main(){
    //Declare variables with type double to store the inputs from
    //the user. 
    double billingAmount,payingAmount,credit,penalty,balance;
    cout<<"Please enter the billing amount: ";
    cin>>billingAmount;
    cout<<"Please enter the payment amount: ";
    cin>>payingAmount;

    //Conditions to check whether the user payment is equal to the
    //billing amount, 50% of the billing amount, or 20% above and 50% below 
    //the billing amount to determine the penalty, or may be credit.
    if(payingAmount==billingAmount){
        if(billingAmount*0.01 > 10)
            credit = 10;
        else
            credit = billingAmount*0.01;
        balance = 0;
    }
    //If the payment is above 50% of the billingAmount.
    else if (payingAmount>=(billingAmount*0.50)){
        balance = billingAmount-payingAmount;
        penalty = balance*0.05;
        credit=0;
    }
    //If the payment is above 20% and below 50% of the billingAmount.
    else if(payingAmount>(billingAmount*0.20)&&
                payingAmount<(billingAmount*0.50)){
        balance = billingAmount-payingAmount;
        penalty = balance*0.10;
        credit=0;
    }
    //If the payment is below 20% of the billingAmount.
    else{
        balance = billingAmount-payingAmount;
        penalty = balance*0.20;
        credit=0;
    }
    cout<<"Balance Remaining: $"<<balance<<endl;
    cout<<"Penalty: $"<<penalty<<endl;
    cout<<"Credit: $"<<credit<<endl;
}