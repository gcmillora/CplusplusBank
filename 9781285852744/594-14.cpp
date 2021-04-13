#include<iostream>

using namespace std;

int main(){
    //Initialize an array of type double
    //with the following values.
    double array[]={2.5,3.9,4.8,6.2,6.2,
    7.4,7.9,8.5,8.5,9.9};

    //A loop structure to traverse the array from
    //the first element to the last.
    for(int ctr=0;ctr<10;ctr++){
        //If an element at index ctr is greater than
        //an element after it, then the elements
        //are out of order or is not in non-decreasing
        //order.
        if(array[ctr]>array[ctr+1]&&ctr!=9){
            cout<<array[ctr]<<" and "<<array[ctr+1]
            <<" elements of array are out of order."
            <<endl;
        }
    }
    cout<<"Elements are in order."<<endl;   
}