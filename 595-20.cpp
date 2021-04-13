#include<iostream>

using namespace std;

void tryMe(int x[], int size){
    cout<<"Hello world";
}

int main(){
    int array[5];
    int array2[15];
    double sample[10];
    tryMe(sample, 5);
    for(int ctr=0; ctr<5;ctr++){
        array[ctr] = ctr*ctr-2;
    }
    cout<<"Array 1: ";
    for(int ctr = 0; ctr<5;ctr++){
        cout<<array[ctr]<<" ";
    } 
    cout<<endl;
    for (int ctr = 0;ctr<5;ctr++){
        array2[ctr]=array[ctr] * ctr;
        array2[ctr+5]=array[4-ctr]+ctr;
        array2[ctr+10]=array2[9-ctr]+array2[ctr];
    }
    cout<<"Array 2: ";
    for (int ctr = 0;ctr< 7;ctr++)
        cout <<array2[ctr]<<" ";
    cout<<endl;
    return 0;
}
