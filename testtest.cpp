#include<iostream>

using namespace std;

//A function that will output the quotient of
//the argument number2 divided by number1 if 
//number1 is a non-zero value.
void testfunc(float number1,float number2){
    if(number1!=0)
        cout<<number2/number1;
    else
        cout<<"The second number cannot be"
        <<"divded by the first number because"
        <<"the first number is equal to 0";
}

int main(){
    cout<<"Testing the function!"<<endl;
    cout<<"[1.4,5.2]: ";
    testfunc(1.4,5.2);
    cout<<endl;
    cout<<"[0,10.53]: ";
    testfunc(0,10.53);
    cout<<endl;
    cout<<"[2,10.0]: ";
    testfunc(2,10.0);
    cout<<endl;
}