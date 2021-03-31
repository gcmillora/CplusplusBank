#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

//A function prototype, includes the
//name of the function, return type,
//and functionparameters.
int sumOfTwoNumbers(int,int);

int main(){
    cout<<sumOfTwoNumbers(3,4);
}

//Function definition, it includes the
//function body. Compiler executes the
//code in the function body.
int sumOfTwoNumbers(int x,int y){
    return x+y;
}