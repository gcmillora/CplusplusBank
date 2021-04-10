#include<iostream>

using namespace std;

int main(){
    //Declare an array of type integer of size 8.
    int array[8];

    //Set the first element of the array to 1, and 
    //the second element to 2.
    array[0] = 1;
    array[1] = 2;

    //A loop statement to traverse the array from the
    //third element until the last element.
    for(int ctr=2;ctr<8;ctr++){
        //Set the value of index ctr to array[ctr-1]
        //times array[ctr-1].
        array[ctr] = array[ctr-1] * array[ctr-2];

        //If ctr is greater than 5, then array[ctr] is
        //equal to array[ctr] - array[ctr-1].
        if(ctr>5)
            array[ctr]=array[ctr] -array[ctr-1];
    }
    
    for(int ctr=0;ctr<8;ctr++){
        cout<<array[ctr]<<" ";
    }
}