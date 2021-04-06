#include<iostream>

using namespace std;


enum triangleType {EQUILATERAL,RIGHT,ISOSCELES,SCALENE};

int main(){
    triangleType triangle;
    triangle = RIGHT;
    cout<<"Index: "<<triangle<<endl;
    return 0;
}