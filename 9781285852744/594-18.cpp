#include<iostream>

using namespace std;

int main(){
    //Declare and initialize an array with the following values.
    int array[] = {3,8,10,13,6,11};

    //Get the length of the array by dividing the size of the array
    //by the size of one of its element, or the data type.
    int length = sizeof(array)/sizeof(int);

    //A loop statement to output every component of the array. Use
    //the length computed as the condition for the for-loop structure.
    for(int ctr=0;ctr<length;ctr++){
        cout<<array[ctr]<<" ";
    }

    //Set the first 5 values of the array to the element of the index
    //minus 3 times the next element of that index.
    for(int ctr=0;ctr<5;ctr++){
        array[ctr] -= (3*array[ctr+1]);
    }
    cout<<endl<<"Updated array: ";
     for(int ctr=0;ctr<length;ctr++){
        cout<<array[ctr]<<" ";
    }


}