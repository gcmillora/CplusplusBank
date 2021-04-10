#include<iostream>
#include <string>

using namespace std;

void getData(int num1[],int num2[]){
    string fnum;
    string snum;
    cout<<"First Number: ";
    cin>>fnum;
    cout<<"Second Number: ";
    cin>>snum;
    for(int ctr=0;ctr<fnum.length();ctr++)
        num1[ctr] = static_cast<int>(fnum[ctr])-static_cast<int>('0');
    for(int ctr=0;ctr<snum.length();ctr++)
        num2[ctr] = static_cast<int>(snum[ctr])-static_cast<int>('0');
}

int main(){
    int num1[20];
    int num2[20];
    getData(num1,num2);
}