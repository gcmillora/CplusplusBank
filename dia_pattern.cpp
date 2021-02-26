#include<iostream>

using namespace std;

void recursivePrint(int counter);

int main(){
    int length;
    cout<<"Please input the length of the diamond (middle length): ";
    cin>> length;
    recursivePrint(length);
}

void recursivePrint(int counter){
    int sp;
    static int stars = 0;
    if(counter < 1) return;
    else{
        sp = counter-1;
        stars++;
        for(int ctr=0;ctr<sp;ctr++){
            cout<<" ";
        }
        for(int ctr=0;ctr<stars;ctr++){
            cout<<"* ";
        }
        cout<<endl;
    recursivePrint(--counter);
    sp = counter+1;
    stars = stars - 1;
    for(int ctr=0;ctr<sp;ctr++){
        cout<<" ";
    }
    for(int ctr=0;ctr<stars;ctr++){
        cout<<"* ";
    }
    cout<<endl;
}
}