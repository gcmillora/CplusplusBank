#include<iostream>
#include<string.h>

using namespace std;

//Defining a function that checks whether the passed string is a 
//palindrome. Compares the first and last characters of the string,
//if true, then proceed to checking the second character from the start
//and the second character from the end, and so on. If for all characters
//it is true then it is a palindrome, else it is not. 

bool isPalindrome(string str){
    int length = str.length();
    for (int ctr=0; ctr<length/2; ctr++){
        //Modified the provided example in the book, to treat every character
        //as its lowercase correspondence, i.e. aBbA is still considered
        //a palindrome. Use the built-in function, tolower to convert the char
        //to lowercase.
        if(tolower(str[ctr])!=tolower(str[length-1-ctr])){
            return false;
        }
    }
    return true;
}


int main(){
    //Declare a variable with type string to store the input from the user.
    string input;
    cout<<"Please input a string: ";
    cin >>input;
    //Use the function isPalindrome(string str) as a condition statement. If
    //the function returns true then the string is a palindrome, else, it is
    //not a palindrome.
    if(isPalindrome(input)){
        cout<<"The string "+input+" is a palindrome."<<endl;
    }
    else{
        cout<<"The string "+input+" is not palindrome."<<endl;
    }
}
