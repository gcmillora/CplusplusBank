#include<iostream>

using namespace std;

//Function prototype
//Function is_vwl will check whether the character
//from the string is a vowel or not, the vowels are
//A,E,I,O,U.
bool is_vwl(char letter);

//Function vowels is a recursive function that will
//count the number of vowels found in the string.
int vowels(string input, int length);

int main(){
    //Declare a variable of type string to store the input
    //from the user.
    string input;
    cout<<"Please enter a string: ";
    cin>>input;
    //Call the function 'vowels(string input, int length)' to
    //count the number of vowels found in the string.
    cout<<"Count: " << vowels(input,input.length());
}

//Function definitions
//A helper function to check whether the character is a
//vowel or not, returns true if yes, else, return false.
bool is_vwl(char letter){
    letter = tolower(letter);
    if(letter == 'a'||letter == 'e'||letter == 'i'||
    letter == 'o'||letter == 'u') return true;
    else return false;
}
//Recursive function to count the number of vowels. It
//returns itself with the arguments, input and length--,
//plus the value of the helper function to check if the
//character is vowel or not.
//Example (Input = aBba):
//Recursive call: vowels(aBba,4) + is_vwl(a)
//Recursive call: vowels(aBba,3) + is_vwl(b)
//Recursive call: vowels(aBba,2) + is_vwl(B)
//and so on.
int vowels(string input, int length){
    if(length==1){
        return is_vwl(input[length-1]);
    }
    return vowels(input,length-1) + is_vwl(input[length-1]);
}