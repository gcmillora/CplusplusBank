#include<iostream>

using namespace std;

void initialize_(int array[]){
    for(int ctr=0;ctr<50;ctr++)
        array[ctr] = -1;
}
int main(){
    //Declaration of an array of size 50;
    int alpha[50];

    //Initialize the elements of alpha to -1.
    initialize_(alpha);

    //Output the first element of the array.
    cout<<"First Element: "<<alpha[0];
    cout<<endl;

    //Set the 25th element of the array to 62.
    alpha[24] = 62;

    //Set the 10th element of the array to 3
    //times the 50th element of the array plus
    //10.
    alpha[9] = 3*alpha[49]+10;

    //A for loop to output the element of the array
    //if the index is a multiple of 2 or 3.
    for(int ctr=0;ctr<50;ctr++){
        if(ctr%2==0||
        ctr%3==0)
        cout<<alpha[ctr]<<" ";
    }
    cout<<endl;
    //Output the last element of the array.
    cout<<"Last Element: "<<alpha[49];
    cout<<endl;

    //Output the elements of an array and for every
    //15 elements, create a new line.
    for(int ctr=1;ctr<=50;ctr++){
        cout<<alpha[ctr-1]<<" ";
        if(ctr%15==0) cout<<endl;
    }
    //Increment all the even index of the array.
    for(int ctr=0;ctr<50;ctr+=2){
        alpha[ctr]++;
    }

    //Create an array where the elements is the 
    //difference of consecutive elements of alpha.
    int diffAlpha[50];
    for(int ctr=0;ctr<50;ctr++){
        if(ctr==49) diffAlpha[ctr] = alpha[ctr];
        else diffAlpha[ctr] = alpha[ctr] - alpha[ctr+1];
    }
}