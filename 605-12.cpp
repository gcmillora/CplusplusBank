#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void getData(string names[], float miles[][7]){
    cout<<"Reading data from text file..."<<endl;
    ifstream inputFile("file.txt");
    for(int ctr=0;ctr<5;ctr++){
        inputFile >> names[ctr];
        for(int ctr2=0;ctr2<7;ctr2++)
            inputFile >> miles[ctr][ctr2];
    }
    inputFile.close();
}

void getTotalAvg(float total[],float avg[],float miles[][7]){
    for(int ctr=0;ctr<5;ctr++){
        total[ctr] = 0;
        for(int ctr2=0;ctr2<7;ctr2++){
            total[ctr] += miles[ctr][ctr2];
        }
        avg[ctr] = total[ctr]/7;
    }
}

void displayData(string names[],float miles[][7],float total[], float avg[]){
    for(int ctr=0;ctr<5;ctr++){
        cout<<"Runner Name: "<<names[ctr]<<endl;
        cout<<"Total Miles Ran: "<<total[ctr]<<endl;
        cout<<"Average Miles Ran in a week: "<<avg[ctr]<<endl;
        for(int ctr2=0;ctr2<7;crt2++){
            cout<<miles[ctr][ctr2]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    string names[5];
    float miles[5][7];
    float total[5];
    float avg[5];

    getData(names,miles);
    getTotalAvg(total,avg,miles);
    displayData(names,miles,total,avg);

}