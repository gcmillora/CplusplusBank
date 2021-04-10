#include<iostream>

using namespace std;

int main(){
    int array[10];
    //A for loop statement to set the element
    //at index ctr with a user input.
    for(int ctr=0;ctr<10;ctr++){
        cin>>array[ctr];
    }
    
    //A for loop to output the elements of the
    //array.
    for(int ctr=0;ctr<10;ctr++){
        cout<<array[ctr]<<" ";
    }
    cout<<endl;
}