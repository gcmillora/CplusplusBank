#include<iostream>

using namespace std;

int main(){
    char name[8] = "Shelly";
    cout<<name;
    cout<<endl;
    for(int ctr=0;ctr<6;ctr++){
        cout<<name[ctr];
    }
    cout<<endl;
    int j=0;
    while(name[j]!='\0')
        cout<<name[j++];
    cout<<endl;
    int ctr2 = 0;
    while(ctr2<8){
        cout<<name[ctr2++];
    }
}