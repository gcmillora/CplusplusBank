#include<stdio.h>
#include<iostream>

using namespace std;

int main(){
    int number;
    cout<<"Please input a number: ";
    cin>> number;
    if (number > 0) cout<<number<<" is a positive number."<<endl;
    else if (number < 0) cout<< number << " is a negative number." <<endl;
    else cout<< number << "is equal to zero."<<endl;
    return 0;

}