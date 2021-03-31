#include<iostream>

using namespace std;

//A function that uses pass-by-reference and pass-by value,
//to count the number of zero,odd, and even digits of a number.
void countNumber(long long x, int& even, int& odd, int& zero){
    int remainder = 0;
    while(x!=0){
        remainder = x % 10;
        if(remainder == 0) 
            zero++;
        else if(remainder%2==0)
            even++;
        else
            odd++;
        x/=10;
    }
}

int main(){
    //Declare a variable of type long long, to store
    //the input from the user.
    long long number = 0;
    int even = 0,odd=0,zero=0;
    cout<<"Please enter a number: ";
    cin>> number;

    //Call the function countNumber and pass the arguments
    //needed by the function.
    countNumber(number,even,odd,zero);
    cout<<"Count Even: "<<even<<endl;
    cout<<"Count Odd: "<<odd<<endl;
    cout<<"Count Zero: "<<zero<<endl;
}