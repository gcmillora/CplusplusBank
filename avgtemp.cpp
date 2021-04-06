#include<iostream>

using namespace std;

//A constant string array where the elements are the months
//of a year.
const string months[12] = {"January","February","March",
                "April","May","June","July","August",
                "September","October","November","December"};

//A function to populate the array from getting data
//from the user. The user inputs the average low and 
//average high temperature of a month.
void getData(double temp[][2]){
    for(int ctr=0;ctr<12;ctr++){
        cout<<months[ctr]<<": "<<endl;
        for(int ctr2=0;ctr2<2;ctr2++){
            if(!ctr2){
            cout<<"\tAvg Low: ";
            cin>>temp[ctr][ctr2];
            }
            else{
                cout<<"\tAvg High: ";
                cin>>temp[ctr][ctr2];
            }
        }
    }
}

//A function to get the average of the high
//temperatures of all the months.
double averageHigh(double temp[][2]){
    double average=0;
    for(int ctr=0;ctr<12;ctr++){
        average+=temp[ctr][1];
    }
    return average/12;
}

//A function to get the average of the low
//temperatuers of all the months.
double averageLow(double temp[][2]){
    double average=0;
    for(int ctr=0;ctr<12;ctr++){
        average+=temp[ctr][0];
    }
    return average/12;
}

//A function to get the index of the highest
//temperature in a year.
int indexHighTemp(double temp[][2]){
    int index=0;
    int max = temp[0][1];
    for(int ctr=0;ctr<12;ctr++){
        if(temp[ctr][1]>max){
            max = temp[ctr][1];
            index = ctr;
        }
    }
    return index;
}

//A function to get the index of the lowest
//temperature in a year.
int indexLowTemp(double temp[][2]){
    int index=0;
    int min = temp[0][0];
    for(int ctr=0;ctr<12;ctr++){
        if(temp[ctr][0]<min){
            min = temp[ctr][0];
            index = ctr;
        }
    }
    return index;
}

int main(){
    double temp[12][2];
    getData(temp);
    double avg_high = averageHigh(temp);
    double avg_low = averageLow(temp);
    cout<<"Average High Temperature: "<<avg_high;
    cout<<endl;
    cout<<"Average Low Temperature: "<<avg_low;
    cout<<endl;
    int index_high = indexHighTemp(temp);
    int index_low = indexLowTemp(temp);
    cout<<"Index of Highest Temperature: ["<<index_high<<"][1]";
    cout<<endl;
    cout<<"Index of Highest Temperature: ["<<index_low<<"][0]";
}