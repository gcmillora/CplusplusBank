#include<iostream>
#include<cmath>

using namespace std;

int main(){
    //Declare an array of integer to store the input
    //from the user.
    int std_numbers[100];
    int length;
    int mean = 0;
    cout<<"Enter how many numbers: ";
    cin>> length;
    
    //Use a loop to get the values from the user and
    //add each value to the variable 'mean'.
    for(int ctr=0;ctr<length;ctr++){
        cout<<"\tNumber "<<ctr+1<<": ";
        cin>>std_numbers[ctr];
        mean += std_numbers[ctr];
    }

    //In order to get the average, divide the sum of
    //the values by the length of the array.
    mean/= length;

    //Declare a variable of type double to store the
    //value of index [ctr] minus the mean, squared.
    double sum_of=0;
    for(int ctr=0;ctr<length;ctr++){
        sum_of += pow(std_numbers[ctr] - mean,2);

    }

    //Compute the standard deviation as shown in the
    //exercise. Use the pre-built functoin 'sqrt' from
    //the header file 'cmath' to get the square root of
    //the value.z
    double std_dev = sqrt(sum_of/length);
    cout<<"Standard Deviation: "<<std_dev;
}