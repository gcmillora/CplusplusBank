#include<iostream>

using namespace std;

int main(){
    int temp[3][4]= {{6,8,12,9},
                    {17,5,10,6},
                    {14,13,16,20}};
    cout<<"1st Row, 1st Column: " << temp[0][0]<<endl;
    cout<<"1st Row, 4th Column: " <<temp[0][3]<<endl;
    cout<<"3rd Row, 1st Column: " <<temp[2][0]<<endl;
    cout<<"3rd Row, 4th Column: " <<temp[2][3]<<endl;
}