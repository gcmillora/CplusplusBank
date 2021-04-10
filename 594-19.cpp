#include <iostream>

using namespace std;

int main(){

    //Declare an array of type integer and initialize
    //the first two components with 3 and 5.
    int array[7] = {3, 5};

    //A for loop structure that will set the element at
    //index ctr to 3 times the index + 2. Also, it sets
    //the value of the element at index ctr - 1 to the
    //value of that element plus by the element at
    //index ctr.
    //Lastly, it sets the value of the element at index
    //ctr - 2 to the value of that index plus the value
    //of the next element.
    for (int ctr=2;ctr<7;ctr++){
        array[ctr]=3*ctr+2;
        array[ctr-1]=array[ctr-1]+array[ctr];
        array[ctr-2]=array[ctr-2]+array [ctr-1];
    }

    //A for loop structure to output the elements of the
    //array.
    for (int ctr=0;ctr<7;ctr++)
        cout << array[ctr] << " ";
    cout << endl;
    return 0;
}