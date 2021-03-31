#include<iostream>

using namespace std;

//A function that will get the index of the first
//occurence of the smallest value in the array of
//integers. Has the parameters array of integers,
//and the length of the array.
int smallestIndex(int array[], int length){
    int temp = array[0];
    int index = 0;
    for(int ctr=0;ctr<length;ctr++){
        if(temp>array[ctr]) index = ctr;
    }
    return index;
}

int main(){
    //Declare the variables needed for the problem.
    int numbers[10];
    int length=10;
    cout<<"Please input ten (10) numbers: ";
    cout<<endl;
    for(int ctr=0;ctr<length;ctr++){
        cout<<"Enter: ";
        cin>>numbers[ctr];
    }
    
    //Call the function,smallestIndex(int[],int)
    //to get the index of the smallest value in 
    //the array.
    cout<<"Index of Smallest Value: "<<
        smallestIndex(numbers,length);
}