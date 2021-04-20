#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main(){
    char string15[16];
    strcpy(string15,"Hello there");
    strlen(string15);
    string15 = "Jacksonville"; 
    cin >>string15;
    cout <<string15;
    if (string15>="Nice day")
        cout<<string15;
    string15[6] = 't';
}