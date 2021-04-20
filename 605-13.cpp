#include<iostream>

using namespace std;

void getData(string names[],int scores[][5]){
    for(int ctr=0;ctr<10;ctr++){
        cout<<"Student Name: "<<endl;
        cin>>names[ctr];
        cout<<"Scores: ";
        for(int ctr2=0;ctr2<5;ctr2++){
            cin>>scores[ctr][ctr2];
        }
        cout<<endl;
    }
}

void computeAvgGrade(int scores[][5], float avg[],char grade[],float& avg_class){
    int total=0;
    for(int ctr=0;ctr<10;ctr++){
        total = 0;
        for(int ctr2=0;ctr2<5;ctr2++){
            total += scores[ctr][ctr2];
        }
        avg[ctr] = total/5;
        avg_class+= avg[ctr];
        if(avg[ctr]>=90) grade[ctr] = 'A';
        else if(avg[ctr]>=80) grade[ctr] = 'B';
        else if(avg[ctr]>=70) grade[ctr] = 'C';
        else if(avg[ctr]>=60) grade[ctr] = 'D';
        else if(avg[ctr]>=50) grade[ctr] = 'F';
    }
    avg_class = avg_class/7;
}

void displayGrade(int scores[][5], float avg[],char grade[], string names[], float avg_class){ 
    for(int ctr=0;ctr<10;ctr++){
        cout<<"Student Name: "<<names[ctr]<<endl;
        cout<<"Average Grade: "<<avg[ctr]<<endl;
        cout<<"Grade: "<<grade[ctr]<<endl;
        cout<<"Scores: ";
        for(int ctr2=0;ctr2<5;ctr2++){
            cout<<scores[ctr][ctr2]<<" ";
        }
        cout<<endl;
    }
    cout<<"Average of the class: "<< avg_class<<endl;
}
int main(){
    string names[10];
    int scores[10][5];
    char grade[10];
    float avg[10];
    float avg_class=0;
    getData(names,scores);
    computeAvgGrade(scores,avg,grade,avg_class);
    displayGrade(scores,avg,grade,names,avg_class);
}