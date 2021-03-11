#include<iostream>

using namespace std;

bool isPalindrome(string str){
    int length = str.length();
    for(int ctr=0; ctr<length/2; ctr++){
        if(tolower(str[ctr])!= tolower(str[length-1-ctr]))
            
             return false;
    }
    return true;
}

int main(){
    if(isPalindrome("abba")){
        cout<<"HELLO";
    }
    else{
        cout<<"hello";
    }
}