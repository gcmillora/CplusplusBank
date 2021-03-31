#include<iostream>
#define MAX 30
using namespace std;

int main(){
    char array[MAX];
    cout<<"Please enter a string: ";
    cin>>array;
    cout<<endl<<"Uppercase Form: ";

    //A for-loop that will convert each character
    //into its uppercase form. If the character does
    //not have an uppercase form, then nothing will be
    //done.
    for(int ctr=0;ctr<MAX;ctr++){
        array[ctr] = toupper(array[ctr]);
    }

    //A for-loop to output the elements of the character
    //array.
    for(int ctr=0;ctr<MAX;ctr++){
        cout<<array[ctr];
    }

}