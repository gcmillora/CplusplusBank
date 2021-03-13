#include<iostream>
#include<cmath>

using namespace std;

//A function that returns the speed inputted by the
//user.
double getSpeed(){
    double speed;
    cout<<"Please input the wind speed in mph: ";
    cin>>speed;
    return speed;
}

//A function that returns the temperature in fahrenheit
//inputted by the user.
double getTemp(){
    double temp;
    cout<<"Please input the temperature in Fahrenheit: ";
    cin>>temp;
    return temp;
}

//Computes the windchill factor using the mathematical
//operations from the header file, <cmath>. Returns
//the factor.
double computeFactor(double speed, double temp){
    return 35.74+0.6215*temp-35.75*pow(speed,0.16)+0.4275
        *temp*pow(speed,0.16);
}


int main(){
    //Call the function and assign to a variable of type
    //double.
    double wind_speed = getSpeed();
    double temperature = getTemp();

    //Pass the wind speed and temperature to the function
    //computeFactor(double,double) to compute for the windchill
    //factor.
    cout<<"Windchill Factor: "<<computeFactor(wind_speed,temperature);
}