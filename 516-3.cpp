#include<iostream>

using namespace std;

//A function to check if a character is a vowel,
//a,e,i,o, and u including the uppercase format.
//Returns true if it is evaluated as a vowel, false
//otherwise.
bool checkVowel(char letter){
    bool check;
    if(letter=='A' || letter=='a') return true;
    if(letter=='E' || letter=='e') return true;
    if(letter=='I' || letter=='i') return true;
    if(letter=='O' || letter=='o') return true;
    if(letter=='U' || letter=='u') return true;
    return false;
}

//A function to remove the vowels in a string.
//Uses the function checkVowel defined above, to
//identify which character index are vowels. It
//uses the function substr to get the index of 
//which are non-vowel characters and append to a
//resulting string.

string removeVowel(string sample){
    string result="";
    int ctr=0;
    while(ctr<sample.length()){
        if(checkVowel(sample[ctr])){
            ctr++;
            continue;
        }
        else{
            //A non-vowel character is found, create
            //a temporary variable to hold the starting
            //position of the occurence and check the
            //proceeding index until a vowel is reached.

            int temp=ctr;
            int steps=1;//Counter for the length of the substring
            while(!checkVowel(sample[ctr+1])){
                steps++;
                ctr++;
            }
            result+=sample.substr(temp,steps);
            ctr++;
        }
    }
    return result;
}

int main(){
    string sample ="WorlD";
    string result = removeVowel(sample);
    cout<<"Sample input string: "<<sample<<endl;
    cout<<"Resulting string: "<<result<<endl;
}