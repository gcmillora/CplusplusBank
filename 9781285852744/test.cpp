#include<iostream>

namespace mySpace{
    const double RATE = 15.35;
    int a = 3;
}

using namespace std;

int main(){
    int num;
    cin>>num;
    mySpace::a = num;
    cout<<mySpace::RATE<<" "<<mySpace::a+2<<" "<<num<<endl;
    return 0;
}