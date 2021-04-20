#include<iostream>

using namespace std;

int main(){
    int count = 0;
    int array[5];
    
    array[0] = 5;
    for(int ctr=0;ctr<5;ctr++){
        array[ctr]= 5*ctr+10;
        array[ctr-1] = array[ctr] - 4;
    }
    cout<<"List elements: ";
    for(int ctr=0;ctr<5;ctr++){
        cout<<array[ctr]<<" ";
    }
    cout<<endl;
    return 0;
}