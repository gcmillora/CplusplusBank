#include<iostream>

using namespace std;

//An enumeration type with the values, scalene, isosceles, equilateral,
//and noTriangle.
enum triangleType {scalene,isosceles, equilateral, noTriangle};

//A function that returns a value of type triangleType. It has three
//parameters, which are the sides of the triangles. The function
//determines the type of the triangle by evaluating the sides of the
//triangles.

triangleType triangleShape(int side1,int side2, int side3){
    triangleType sample;
    
    //Check if the sides can form a triangle.
    if(((side1+side2) > side3)&&((side3+side2) > side1)&&
                    ((side1+side3) > side2)){
        //Check if the sides form an equilateral triangle.
        if(side1==side2 && side1==side3){
            sample = equilateral;
        }
        //Check if the sides form a scalene triangle.
        else if((side1!=side2)&&(side1!=side3)&&(side2!=side3)){
            sample = scalene;      
        }
         //Check if the sides form an isosceles triangle.
        else{
            sample = isosceles;
        }
        return sample;
    }
    //If the sides cannot form a triangle then return noTriangle.
    else{
        sample = noTriangle;
        return sample;
    }
}

int main(){
    int side1,side2,side3;
    cout<<"Please input the sides of a triangle: ";
    cin>> side1;
    cin>> side2;
    cin>> side3;
    triangleType shape = triangleShape(side1,side2,side3);
    cout<<"Length of:"<<endl;
    cout<<"Side 1: "<<side1<<endl;
    cout<<"Side 2: "<<side2<<endl;
    cout<<"Side 3: "<<side3<<endl;
    if(shape == equilateral){
        cout<<"Shape of the Triangle: Equilateral"<<endl;
    }
    else if(shape == isosceles){
        cout<<"Shape of the Triangle: Isosceles"<<endl;
    }
    else if(shape == scalene){
        cout<<"Shape of the Triangle: Scalene"<<endl;
    }
    else{
        cout<<"No triangle can be formed from the given sides."<<endl;
    }

}