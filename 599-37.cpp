#include<iostream>
#include<cstring>

using namespace std;

int main(){
    char str1[21];
    char str2[21];
    strcpy(str1,"Sunny Day");
    int length = strlen(str1);
    cout<<length;
    char name[] = "Hello World!";
    strcpy(str2,name);
   if(strcmp(str1,str2)<= 0){
        cout<< str1;
    }
    else cout<< str2;

}