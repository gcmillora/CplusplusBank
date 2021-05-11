#include<iostream>
#include<string>
#include <sstream>

using namespace std;

int main(){
    string data;
    getline(cin,data);
    string array[4];
    istringstream ss(data);
    string dt;
    int ctr=0;
    while(ss >> dt){
        array[ctr] = dt;
        ctr++;
    }

    array[1].replace(0,3,"XXX");
    array[1].replace(4,2,"XX");
    array[1].replace(7,4,"XXXX");
    array[3].replace(0,array[2].length(),array[2].length(),'X');
    for(int ctr=0;ctr<3;ctr++){
        cout<<array[ctr]<<" ";
    }

}