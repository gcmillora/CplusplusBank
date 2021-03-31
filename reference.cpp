#include<iostream>

using namespace std;

//Function prototype for the initialization function
//of the variables with type integer, double and string.
void initialize(int&, double&, string&);

int main(){
    //Declare three variables and assign a random value
    //in order to check if the values changed after initialization.
    int num = 6;
    double num2 = 9.2;
    string sample = "hello world!";
    initialize(num,num2,sample);
    cout<<"After Referencing"<<endl;
    cout<<num<<endl;
    cout<<num2<<endl;
    cout<<sample<<endl;
    return 0;
}

//In order to use pass-by-reference, use the notation, &,
//to tell that the parameters are of reference type.
void initialize(int& num1, double& num2, string& sample){
    //Set the values of the integer to 0, double to 0 and
    //the string to an empty string.
    num1 = 0;
    num2 = 0;
    sample="";
}