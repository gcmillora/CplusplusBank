#include<iostream>
#include<cmath>

using namespace std;

//A function to compute for the standard deviation
//o 5 numbers. The variable sumOf is the summation
//of (each value - mean) squared. This can be done
//with the use of a loop, for-loop in this case.
//Returns the standard deviation.
double std_dev(double array[], double mean){
    double sumOf=0,stddev;
    for(int ctr=0;ctr<5;ctr++){
        sumOf+= pow((array[ctr]-mean),2);
    }
    stddev = sqrt(sumOf/5);
    return stddev;
}

//A function to compute for the mean of an array of
//doubles. Uses a for-loop structure to get the sum
//of all the values. Returns the mean.
double mean(double array[]){
    double mean=0;
    for(int ctr=0;ctr<5;ctr++){
        mean+= array[ctr];
    }
    mean = mean/5;
    return mean;
}

int main(){
    //Declare an array of double to store the input
    //from the user. Compute the mean and standard deviation
    //by calling the function mean(double[]) and function
    //std_dev(doube[], double);

    double array[5];
    for(int ctr=0;ctr<5;ctr++){
        cout<<"Please input a number: ";
        cin>>array[ctr];
    }
    double mean_ar = mean(array);
    double dev = std_dev(array, mean_ar);
    cout<<"Standard Deviation: "<<dev;
}