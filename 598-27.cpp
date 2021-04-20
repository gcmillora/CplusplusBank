#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    const double PI = 3.14159;
    double cylinderRadii[5] = {3.5,7.2,10.5,9.8,6.5};
    double cylinderHeights[5] = {10.7,6.5,12.0,10.5,8.0};
    double cylinderVolume[5];

    cout<<fixed<<showpoint<<setprecision(2);

    for(int ctr=0;ctr<5;ctr++){
        cylinderVolume[ctr] = 2*PI*cylinderRadii[ctr]*cylinderHeights[ctr];
    }
    for(int ctr=0;ctr<5;ctr++){
        cout<<ctr+1<<" "<< cylinderRadii[ctr] << " " << cylinderHeights[ctr]
        <<" "<<cylinderVolume[ctr]<< endl;
    }
}

int plus(int array[]){
    for(int ctr=0;ctr<5;ctr++){
        array[ctr] += array[ctr];
    }
}