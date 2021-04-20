#include<iostream>
#include <fstream>

using namespace std;

int main(){

    ifstream infile; 
    infile.open("afile.dat"); 
    int data, total=0;

    int cars[10];
    for(int ctr=0;ctr<10;ctr++){
        infile >> data;
        cars[ctr] = data;
    }

    for(int ctr=0; ctr<10;ctr++){
        cout<<"Salesperson #"<<ctr+1<<": "<<cars[ctr];
    }

    int max=0;
    for(int ctr=0;ctr<10;ctr++){
        if(cars[ctr] > cars[max])
                max = ctr;
        total += cars[ctr];
    }

    cout<<"Total Sold Cars: "<<total<<endl;
    cout<<"Best Salesperson #: "<<max+1<<endl;
    
}