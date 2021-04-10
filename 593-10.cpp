#include<iostream>

using namespace std;

int main(){
    //Declare an array of type double with a
    //size of 6.
    double array[6];

    //Set the value of the first element of
    //the array to 2.5.
    array[0] = 2.5;

    //A loop statement to traverse the array.
    for(int ctr=1;ctr<6;ctr++){
        //Set the element at index ctr to ctr
        //multiplied by the element at index 
        //ctr-1.
        array[ctr]=ctr*array[ctr-1];

        //If ctr is greater than 3 then the
        //element at index ctr is equal to
        //the element at index ctr divided
        //by 2.
        if(ctr>3)
            array[ctr] = array[ctr]/2;
    }
    for(int ctr=0;ctr<6;ctr++)
        cout<<array[ctr]<<" ";
}   