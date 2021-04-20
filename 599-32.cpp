#include<iostream>
#include<string>

using namespace std;

int main(){
    string names[] = {"Blair, Cindy","Johnson, Chris",
            "Mann, Sheila"};
    string str1,str2;
    char ch= ',';
    int pos,length;
    for(auto &str: names){
        pos = str.find(ch);
        length = str.length();
        str1 = str.substr(0,pos);
        str2 = str.substr(pos+2,length-pos-1);
        str = str2+ ' '+ str1;
    }
    for(auto str:names)
        cout<<str<<endl;
    }