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
    string input;
    int count=0; //Variable of type int to store the count.
    cout<<"Please input a character: ";
    cin>> input;

    //A loop to traverse the elements of the string.
    //Use a for-loop with condition ctr<input.length().
    for(int ctr=0;ctr<input.length();ctr++){
        //Use a condition statement to count the number
        //of vowels. Call the function isVowel(char) to 
        //evaluate the character. If true, then increment
        //count else do nothing and continue with the loop.
        if(isVowel(input[ctr]))
            count++;
    }
    cout<<"Number of Vowels: "<<count;

    return 0;
}