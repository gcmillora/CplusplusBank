#include<iostream>

using namespace std;

int main(){
    int array1[5];
    int array2[10];

    for(int ctr=0;ctr<5;ctr++){
        array1[ctr] = 5*ctr+3;
    }

    cout<<"One contains: ";
    for(int ctr=0;ctr<5;ctr++){
        cout<<array1[ctr] <<" ";
    }
    cout<<endl;

    for(int ctr=0;ctr<5;ctr++){
        array2[ctr] = 2*array1[ctr]-1;
        array2[ctr+5]= array1[4-ctr]+array2[ctr];
    }

    cout<<"Two contains: ";
    for(int ctr=0;ctr<10;ctr++){
        cout<<array2[ctr]<<" ";
    }
    cout<<endl;
    return 0;
}