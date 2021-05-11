#include<iostream>

using namespace std;


void print(int array[][7], int row){
    for(int ctr=0;ctr<row;ctr++){
        for(int ctr2=0;ctr2<7;ctr2++){
            cout<<array[ctr][ctr2]<<" ";
        }
    cout<<endl;
    }
}
int main(){
    int times[30][7];
    int speed[15][7];
    int trees[100][7];
    int students[50][7];

    print(times,30);
    print(speed,15);
    print(trees,100);
    print(students,50);
}