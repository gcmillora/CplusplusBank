#include<iostream>

using namespace std;

int main(){
    //Declare a variable with integer type to store the input from the user.
    int number;
    //Gets an input from the user. 
    cout<<"Please input a number between 0 and 35: ";
    cin >> number;
    
    //Using a condition to check whether the number is between 0 and 35
    //If the number is not from 0 to 35, then print the necessary output.
    if (number < 0&& number > 35) 
        cout<<"Input a number between 0 and 35!";
    
    //If the number is less than 10, output the number. i.e. Output: 0, Output: 5
    else if(number<10)
        cout<<"Output: "<<number;
    
    //Else, if the number is greater than or equal to 10, subtract 10 from the number
    //in order to start from 0 and add the value of character 'A' from the ASCII table.
    //Using the hint provided by thr book, use static_cast<char> to cast the value into
    //a character.
    //Example: static_cast<char> 65 is equal to A,  
    //         static_cast<char> 68 is equal to D.

    else
        cout <<"Output: "<<static_cast<char>( number - 10 + 'A' );
    return 0;
}

