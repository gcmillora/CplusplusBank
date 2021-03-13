#include<iostream>

using namespace std;

//A function that checks if a character is
//a vowel, if it is a vowel, then return a 
//value true, else return false.
bool isVowel(char input){
    //Conditions to check if the character is vowel
    //i.e. 'A','E','I','O','U'.
    if( input == 'A'||input == 'E'||input == 'I' ||
        input == 'O'||input == 'U' ||input == 'a'||
        input == 'e'||input == 'i'||input == 'o'||
        input == 'u')
        return true;
    else
        return false;
}

int main(){
    //Declare a variable of type char to store the
    //input from the user.
    char input;
    cout<<"Please input a character: ";
    cin>> input;
    
    //Use a condition statement to print the necessary
    //output. Call the function isVowel(char) to evaluate
    //the character. Return true if it is a vowel, else 
    //return false.
    if(isVowel(input))
        cout<<"The character is a vowel."<<endl;
    else   
        cout<<"The character is not a vowel."<<endl;
    return 0;
}