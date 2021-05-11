#include<iostream>

using namespace std;

int main(){
    int temp[3][4]= {{6,8,12,9},{17,5,10,6},{14,13,16,20}};
    for(int ctr=0;ctr<3;ctr++){
        for(int ctr2=0;ctr2<4;ctr2++)
            cout<<temp[ctr][ctr2]<<" ";
        cout<<endl;
    }
}