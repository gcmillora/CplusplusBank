#include<iostream>

using namespace std;

//Function prototype
//Create a prototype function of type void with an 
//integer variable as parameter. Only purpose is to 
//print the pattern specified and does not need to 
//return anything.
void recursivePrint(int counter);

int main(){
    //Declare a variable with type integer to store
    //the input from the user.
    int counter;
    cout<<"Please enter how many lines: ";
    cin>>counter;
    //Call the function and pass 'counter' as an argument.
    recursivePrint(counter);
    return 0;
}

//Function that recursively calls itself to print the
//pattern. In example, when counter = 2, prints '**' in
//first call, then prints "*". Using recursion, it then prints
//the other half of the pattern, prints '*', since recursivePrint(1)
//is still not finished, and so on. Lastly, it finishes 
//recursivePrint(2), prints "**".

void recursivePrint(int counter){
    if(counter>0){
        for(int ctr = 0;ctr<counter;ctr++) cout<<"*";
        cout<<"\n";
        recursivePrint(counter-1);
        for(int ctr=counter;ctr>0;ctr--) cout<<"*";
        cout<<endl;
    }
}