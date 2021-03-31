#include<iostream>

using namespace std;

//A global variable, the value can be changed
//and used anywhere in the code.
int glb;

//Function prototypes of the functions needed
//for the program. For the formal parameters
//with pass-by-reference, &, are the only parameters
//that the value of the actual parameter will change
//from the calling function.
void func1(int&, int);
void func2(int, int&);

int main(){
    int num1 = 2;
    int num2 = 5;
    glb = 6;
    func1(num1,num2);
    cout<<num1<<" "<<num2<<" "<<glb<<endl;
    func2(num1,num2);
    cout<<num1<<" "<<num2<<" "<<glb<<endl;
    return 0;
}

//It is important to take note the order of the
//parameters in order to keep track of the changes
//to the actual parameters.
void func1(int &num1, int num2){
    int x;
    x = num2 + 12;
    num1 = 2 * num2 + 5;
    num2 = x +4;
}

void func2(int num1, int& num2){
    int x;
    x = glb;
    num2 = x * 4;
    glb = num1 - num2;
}