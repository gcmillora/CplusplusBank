#include<iostream>

using namespace std;

//A recursive function that checks if a string is a 
//palindrome. Returns true, if yes, els return false.
bool recursivePalindrome(string word) {
    //Check if the string is of valid length.
    if (word.length() <= 1) return true;

    //Check if the character of the first index is
    //equal to the character of the last index of the
    //string.
    else if (word[0] == word[word.length() - 1]) {
        //Returns a copy of the string, where
        //the first and last character is omitted.
        return recursivePalindrome(
            word.substr(1,word.length() - 2));
    }
    else {
        //If the characters from the first index and
        //last index is not equal, return false.
        return false;
    }
}


int main(){
    //Declare a variable of type string to store the input
    //from the user.
    string input;
    cout <<"Please enter a string: ";
    cin>>input;
    
    //Declare a variable of type bool to store the result from
    //calling the recursive functionm recursivePalindrome().
    bool check = recursivePalindrome(input);
    if(check) cout<<"The string "<<input<<" is a palindrome.";
    else cout << "The string "<<input<<" is not a palindrome.";
    return 0;
}


