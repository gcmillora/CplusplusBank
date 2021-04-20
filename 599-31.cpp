#include<iostream>

using namespace std;

int main(){
    int array[] = {5,7,6,4,8,15,32,40};
    for(auto num: array){
        cout<<num/2<<" ";
    }
    cout<<endl;
    return 0;
}