#include<iostream>
#include<cmath>

using namespace std;
const double PI = 3.1416;

double distance(double c_1,double c_2,double p_1,double p_2){
    return (sqrt(pow((c_2-c_1),2)+pow((p_2-p_1),2)));
}

double radius(double c_1,double c_2,double p_1,double p_2){
    return distance(c_1,c_2,p_1,p_2);
}

double circumference(double r){
    return 2*PI*r;
}


int main(){
    double c_1,c_2,p_1,p_2;
    cout<<"Please enter the center of the circle: ";
    cin>>c_1;
    cin>>c_2;
    cout<<"Please enter a point on the circle: ";
    cin>>p_1;
    cin>>p_2;

}