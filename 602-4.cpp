#include<iostream>
#include<fstream>

using namespace std;

void printData(int data[], int size){
    for(int ctr=0;ctr<size;ctr++){
        cout<<data[ctr]<<" ";
        if(ctr%12==0) cout<<endl;
    }
}

void printRanges(int grades[], int size){
    for(int ctr=0;ctr<size;ctr++){
        cout<<"Range "<<ctr+1<<": "<<grades[ctr]<<endl;
    }
}

void readData(int scores[], int size, int grades[]
        ,ifstream& data){
    for(int ctr=0;ctr<size;ctr++){
        data >> scores[ctr];
        if(scores[ctr]>= 0&& scores[ctr]<=24)
            grades[0]++;
        if(scores[ctr]>= 25&& scores[ctr]<=49)
            grades[1]++;
        if(scores[ctr]>= 50&& scores[ctr]<=74)
            grades[2]++;
        if(scores[ctr]>= 75&& scores[ctr]<=99)
            grades[3]++;
        if(scores[ctr]>= 100&& scores[ctr]<=124)
            grades[4]++;
        if(scores[ctr]>= 125&& scores[ctr]<=149)
            grades[5]++;
        if(scores[ctr]>= 150&& scores[ctr]<=174)
            grades[6]++;
        if(scores[ctr]>= 175&& scores[ctr]<=200)
            grades[7]++;
            
    }
}

int main(){
    int scores[26] = {0};
    int grades[8];
    ifstream inFile;
    inFile.open("data.txt");
    cout<<"Reading data...";
    readData(scores,26,grades,inFile);
    cout<<endl<<"Done..."<<endl;
    printData(scores,26);
    printRanges(grades,8);


}