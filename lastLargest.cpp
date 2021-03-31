#include<iostream>

using namespace std;

//A function that will get the index of the last
//occurence of the largest value in the array of
//integers. Has the parameters array of integers,
//and the length of the array.
int lastLargestIndex(int array[], int length){
    int temp = array[0];
    int index = 0;
    for(int ctr=0;ctr<length;ctr++){
        if(temp<array[ctr]) index = ctr;
    }
    return index;
}

int main(){
    int numbers[10];
    int length=10;
    cout<<"Please input ten (10) numbers: ";
    cout<<endl;
    for(int ctr=0;ctr<length;ctr++){
        cout<<"Enter: ";
        cin>>numbers[ctr];
    }
    
    //Call the function,lastLargestIndex(int[],int)
    //to get the index of the last occurence of the  
    //largest value in the array.
    cout<<"Index of the Largest Value: "<<
        lastLargestIndex(numbers,length);
}