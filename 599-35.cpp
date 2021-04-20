#include<iostream>
#include<cstring>

using namespace std;

int main(){
    char str1[15];
    char str2[15] = "Good day";

    cout<<str1;
    str1=str2;
    if(str1 == str2){
        cout<<"Both strins are of the same length."<<endl;
    }
   // if(strlen(str1)>= strlen(str2)){
       str1=str2;
   // }
    if(strcmp(str1, str2)<0){
        cout<<"str1 is less that str2."<<endl;
    }

}