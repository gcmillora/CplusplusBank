#include<iostream>
#include<cmath>
//Make sure to include the 'cmath' library, to be
//able to use the different functions for mathematical
//operations.

using namespace std;

int main(){
    const double PI = 3.14159;
    //In order to compute for the square root of PI,
    //use the function 'sqrt(double)' from the 'cmath'
    //library.
    cout<<"Square Root of PI: "<< sqrt(PI)<<endl;
    double r;
    cout<<"Please input a radius of the sphere: ";
    cin>> r;
    //The function pow(double,double) from 'cmath'
    //can be used to get the square or cube of a 
    //number.
    double surface_area = 4*PI*pow(r,2);
    double volume = PI*4/3*pow(r,3);
    cout<<"Surface Area: "<<surface_area<<endl;
    cout<<"Volume: "<<volume<<endl;
}