#include<iostream>
#include<math.h>
using namespace std;

int main(){
    //Declare three variables with type double to store the inputs from the user.
    //Use double since math.pow() takes double as its default parameter.
    double s_1,s_2,s_3;
    //Get the length of each side from the user.
    cout<<"Please input the length of the first side: ";
    cin>>s_1;
    cout<<"Please input the length of the second side: ";
    cin>>s_2;
    cout<<"Please input the length of the third side: ";
    cin>>s_3;
    //Use the operator logical OR '||' in order to save multiple lines of else-if
    //if one of the condition is true, then the if statement passes. Check whether the
    //square of two sides is equal to the square of the other side. Repeat this method
    //in every combination of the side, if true, then print that it is a right triangle.
    //Else, output that the triangle is not a right triangle.
    if(pow(s_1,2)+pow(s_2,2)==pow(s_3,2)
        || pow(s_2,2)+pow(s_3,2)==pow(s_1,2)
        || pow(s_1,2)+pow(s_3,2)==pow(s_2,2) ){
        cout<<"The triangle is a right triangle."<<endl;
    }
    else{
        cout<<"The triangle is not a right triangle."<<endl;
    }

    return 0;
}