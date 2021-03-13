#include<iostream>

using namespace std;

int recursive_Sum(int num[], int len){
    //Base-case for the recursive function. If the length 
    //is zero, then stop recurring.
    if(len == 0){
        return num[len];
    }
    else{
    //Returns the sum of the array_int with index 'len'
    //and the next element, [index -1], of the array.
        cout<<"Recursion: "<<num[len]<<endl;
        return num[len] + recursive_Sum(num, len-1);
    }

}

int main(){
    //Declare an array of integers to store the numbers.
    int numbers[6] = {10,11,12,13,14,15};

    //Using the pre-built operator 'sizeof', get the size
    //of the array and divide it with the size of an element
    //in the array.
    int length = sizeof(numbers)/sizeof(numbers[0]);
    //Call the recursive function and store it to a variable
    //of integer type.
    int result = recursive_Sum(numbers,length-1);
    cout<<"Array Sum: " << result;
    
    return 0;

}