#include<iostream>

using namespace std;


//A function to update the value of the variables
//sum and prod. Sum is updated by adding the value
//of num and prod is updated by multiplying to the
//value of num.
void func_test(int& sum, int& prod, int& num){
    sum+=num;
    prod*= num;
}

int main(){
    //Declare and initialize the variables of sum and prod.
    int sum = 0;
    int prod = 1;
    int num;
    for(int ctr=0;ctr<5;ctr++){
        cout<<"Input a number: ";
        cin>>num;
        func_test(sum,prod,num);
        cout<<"Updated sum: "<<sum<<endl;
        cout<<"Updated prod: "<<prod<<endl;
        cout<<"--------------"<<endl;
    }
}