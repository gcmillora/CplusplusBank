#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char name[21];
    char yourName[21];
    char studentName[31];
    cin>> name;
    //cout<<studentName;
    yourName[0] = '\0';
    cout<<yourName;
    //yourName = studentName;
    if (yourName == name)
        studentName = name;
    int x = strcmp(yourName, studentName);
    strcpy(studentName, name);
    cout<<endl;
    for (int j = 0; j < 21; j++)
        cout << name[j];
}