#include<iostream>

using namespace std;

bool isVowel(char letter){
    bool check;
    if(letter=='A' || letter=='a') return true;
    if(letter=='E' || letter=='e') return true;
    if(letter=='I' || letter=='i') return true;
    if(letter=='O' || letter=='o') return true;
    if(letter=='U' || letter=='u') return true;
    return false;
}

string rotate(string sample){
    int len = sample.length();
    string rStr;
    rStr = sample.substr(1,len-1)+sample[0];
    return rStr;
}

string pigLatinString(string pStr){
    int len;
    bool foundVowel;
    int counter;

    if(isVowel(pStr[0]))
        pStr = pStr + "-way";
    else{
        pStr = pStr + '-';
        pStr = rotate(pStr);
        len = pStr.length();
        foundVowel = false;
        for(counter = 1; counter<len-1;counter++)
            if(isVowel(pStr[0])){
                foundVowel = true;
                break;
            }
            else
                pStr = rotate(pStr);

        if(!foundVowel)
            pStr = pStr.substr(1, len)+"-way";
        else
            pStr = pStr +"ay";
    
    }
    return pStr;
}

int main(){

}