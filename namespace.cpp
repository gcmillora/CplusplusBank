#include<iostream>

namespace mySpace{
    const double RATE = 15.35;
    int a = 3;
}

using namespace std;

int main(){
    int num;
    cin>>num;
    cout<<mySpace::RATE<<"\n";
    cout<<mySpace::a<<"\n";
    return 0;
}