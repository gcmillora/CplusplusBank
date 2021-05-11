#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

void traceMe(double& x,double& y,double& z);

int main(){
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"hakdog";
    double one, two, three;
    cout<<"Enter two numbers: ";
    cin>> one;
    cin>>two;
    cout<<endl;
    traceMe(one, two, three);
    cout<<one<<", "<<two<<", "<<three<<endl;
    traceMe(two, one, three);   
    cout<<one<<", "<<two<<", "<<three<<endl;
    
    return 0;
}

void traceMe(double& x,double& y,double& z){
    if(x!=0) z = sqrt(y)/x;
    else{
        cout<<"Enter a non-zero number: ";
        cin>>x;
        cout<<endl;
        z = floor(pow(y,x));
    }
}
