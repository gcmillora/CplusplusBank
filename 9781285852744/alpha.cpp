#include<iostream>

using namespace std;

int main(){
    double alpha[50];
    for(int ctr=0;ctr<50;ctr++){
        if(ctr<25){
            alpha[ctr] = ctr*ctr;
        }
        else if(ctr>24){
            alpha[ctr] = 3*ctr;
        }
    }
    cout<<"[ARRAY OUTPUT]"<<endl;
    for(int ctr=0;ctr<50;ctr++){
       cout<<alpha[ctr]<<" ";
       if((ctr+1)%10==0) cout<<endl;
    }
}