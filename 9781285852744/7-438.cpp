#include<iostream>

using namespace std;

bool caseCheck(char inp){
     if(isupper(inp)) return true;
     else return false;
}

int main(){
    if(caseCheck('A')){
        cout<<"True, uppercase!"<<endl;
    }
    else{
        cout<<"False, lowercase!"<<endl;
    }
    return 0;
}