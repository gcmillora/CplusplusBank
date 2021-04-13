#include<iostream>
#include<cmath>
using namespace std;

int main(){
    //Declare an array of type integer with a size of 5.
    int array[5];

    //Set each element to the value of its index squared.
    for(int ctr=0;ctr<5;ctr++){
        array[ctr] = static_cast<int>(pow(ctr,2.0));
    }
    for(int ctr=0;ctr<5;ctr++){
        cout<<array[ctr]<<" ";
    }
    cout<<endl;

    //Set the 5th element of array to the 4th element
    //multiplied by the 3rd element of the array.
    array[4] = array[3] * array[2];

    //Set the 4th element of array to the 5th element
    //multiplied by the 3rd element of the array.
    array[3] = array[4] - array[2];

    //Set the 1st element of the array to the 6th element
    //which is 0, divided by the 2nd element of the array.
    array[0] = array[5] / array[1];
    for(int ctr=0;ctr<5;ctr++){
        cout<<array[ctr]<<" ";
    }
    cout<<endl;
}