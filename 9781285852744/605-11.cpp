#include<iostream>
#include <string>

using namespace std;

void getData(string num1,string num2){
    getline(cin,num1);
    getline(cin,num2);
}
int main(){
    string str_num1;
    string str_num2;
    getData(str_num1,str_num2);
}