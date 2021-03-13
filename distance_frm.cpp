#include<iostream>
#include<cmath>

using namespace std;
const double PI = 3.1416;


//Functions to  calculate the distance,radius, circumference
//and area. Use the function 'distance' to compute the radius
//of the circle. 
double distance(double c_1,double c_2,double p_1,double p_2){
    double num_1 = pow(c_2 - c_1,2);
    double num_2 = pow(p_2-c_1,2);
    double dist = sqrt((num_1)+num_2);
    return dist;
}

double radius(double c_1,double c_2,double p_1,double p_2){
    return distance(c_1,c_2,p_1,p_2);
}

double circumference(double r){
    return 2*PI*r;
}

double area(double r){
    return PI*pow(r,2);
}


int main(){
    //Declare variables of type double to store the inputs
    //from the user.
    double c_1,c_2,p_1,p_2;
    cout<<"Please enter the center of the circle: ";
    cin>>c_1;
    cin>>c_2;
    cout<<"Please enter a point on the circle: ";
    cin>>p_1;
    cin>>p_2;

    //Call the functions above and store it to a variable
    //of type double. 
    cout<<c_1<<" "<<c_2<<" "<<p_1<<" "<<p_2<<endl;
    cout<<distance(c_1,c_2,p_1,p_2);
    double rad = radius(c_1,c_2,p_1,p_2);
    double cir = circumference(rad);
    double ar = area(rad);
    
    cout<<"The radius of the circle is "<<rad<<endl;
    cout<<"The circumference of the circle is "<<cir<<endl;
    cout<<"The area of the circle is "<<ar<<endl;
    return 0;
}