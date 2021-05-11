#include<iostream>

using namespace std;

int main(){
    int alpha = 5;
    int beta = 10;
    if(beta>=alpha){
        int alpha;
        int temp;
        alpha = 20;
        temp = beta-alpha;
        beta = beta*temp;
        cout<<alpha<<' '<<beta<<endl;
    }
     cout<<alpha<<' '<<beta<<endl;
}