#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){
    cout << fixed << showpoint;
    cout << setprecision(2);
    cout<<abs(-25)<<endl;
    cout<<fabs(-56.38)<<endl;
    cout<<fabs(13.00)<<endl;
    cout<<pow(3.0,2)<<endl;
    cout<<pow(6.2,1.5)<<endl;
    cout<<sqrt(34.56)<<endl;
    cout<<sqrt(144.0)<<endl;
    cout<<sqrt(49.0)*pow(6.0,3.0)/abs(-3)<<endl;
    cout<<floor(13.45)<<endl;
    cout<<ceil(6.5)<<endl;
    cout<<floor(5.89)+ceil(5.89)<<endl;
    cout<<floor(-5.89)+ceil(-2.31)<<endl;
    cout<<floor(-2.3)-ceil(81.2)<<endl;
    cout<<pow(-3.0,5.0)<<endl;
    cout<<pow(3.0,-5.0)<<endl;
    cout<<pow(4.2,1/5.0)<<endl;
}