#include<iostream>

using namespace std;

//A recurisve function to compute the sum of
//the digits of an integer number. Returns the
//digit plus the sum of the next digits.
int sumDigits(int number){
    //Base case for the function. If the number is 0,
    // return 0.
    if(number==0){
        return 0;
    }
    else{
        //Get the next place of the digit and store to
        //integer variable 'place'.
        int place = number/10;

        //Get the next digit using the operator 'modulo %'
        //and store to an integer variable 'digit'.
        int digit = number%10;
        return(digit+sumDigits(place));
    }
}
int main(){
    //Declare a variable of integer type to store the input number
    //from the user. 
    int number;
    cout<<"Please input a number: ";
    cin>>number;

    //Call the recursive function sumDigits() and store into a
    //variable of integer type.
    int sum_digits = sumDigits(number);
    cout<<"Sum of Digits: "<<sum_digits;
}