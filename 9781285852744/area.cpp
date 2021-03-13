#include<iostream>
#include<iomanip>

using namespace std;

const double PI = 3.1419;

double rectangle(double l, double w);
double circle(double r);
double cylinder(double bR, double h);

int main(){
    double radius;
    double height;
    double length, width;
    cout<<fixed<<setprecision(2)<<endl;
    cout<<"This program can calculate the area of a rectangle, "<<
       endl<<"the area of a circle or volume of a cylinder."<<endl;
    cout<<"To run the program enter: "<<endl;
    cout<<"1: To find the area of a rectangle."<<endl;
    cout<<"2: To find the area of a circle."<<endl;
    cout<<"3: To find the volume of a cylinder."<<endl;
    cout<<"-1: To terminate the program."<<endl;
    cout<<endl;

    int choice = 0;
    while(1){
        cin>> choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter the length and the width "
                <<"of the rectangle: ";
                cin>> length >>width;
                cout<<endl;
                cout<<"Area = "<<rectangle(length,width)<<endl;
                break;
            case 2:
                cout<<"Enter the radius of the circle: ";
                cin>> radius;
                cout<<endl;
                cout<<"Area = "<<circle(radius)<<endl;
                break;
            case 3:
                cout<<"Enter the radius of the base and the "
                    <<"height of the cylinder: ";
                cin>>radius>>height;
                cout<<endl;
                cout<<"Volume = "<<cylinder(radius,height)<<endl;
                break;
            case -1: 
                return 0;
            default:
                cout<<"Invalid choice!"<<endl;
        }
    }
    return 0;
}

double rectangle(double l,double w){
    return l * w;
}

double circle(double r){
    return PI*r*r;
}

double cylinder(double bR, double h){
    return PI*bR*bR*h;
}