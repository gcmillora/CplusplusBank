#include<iostream>

using namespace std;

int main(){
    int array[10];
    for(int ctr=0;ctr<5;ctr++){
        //Set the element at index ctr to index multiplied by
        //the index minus 1.
        array[ctr] = ctr*(ctr-1);

        //If the remainder of index divided by 2 is 0, then
        //element at index ctr is equal to the element at that
        //index plus the index.
        if(ctr%2==0)
            array[ctr] = array[ctr] + ctr;

        //Else if the remainder of index divided by 3 is 0, then
        //element at index ctr is equal to the element at that
        //index minus the index.
        else if(ctr%3==0)
            array[ctr] = array[ctr] - ctr;

        //Else if the index is greater than 0 and does not satisfy
        //the conditions set above, then element at index ctr is 
        //equal to the element at that index plus the index.
        else if(ctr>0)
            array[ctr] = array[ctr] - array[ctr-1];
    }
    for(int ctr=0;ctr<5;ctr++){
        cout<<array[ctr]<<" ";
    }
}