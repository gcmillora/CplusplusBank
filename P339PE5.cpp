#include<iostream>

using namespace std;

int main(){
    //Declare variables with type integer to store the input
    //from the user.
    int counter,number;
    cout<<"Please input how many numbers: ";
    cin>> counter;

    //Declare and initialize two integer variables to store
    //the sum of the even numbers and odd numbers.
    int even_sum=0;
    int odd_sum=0;

    //Using a loop to get an input from the user, and
    //check whether the number is an even number or an
    //odd number. Add to its corresponding category, even_sum
    //or odd_sum.
    for(int ctr=0;ctr<counter;ctr++){
        cout<<"Number: ";
        cin>>number;
        if(number%2==0)
            even_sum+=number;
        else
            odd_sum+=number;
    }
    
    //Print the sum of all the even numbers and the sum
    //of all the odd numbers.
    cout<<"Sum of even numbers is "<<even_sum<<endl;
    cout<<"Sum of odd numbers is "<<odd_sum<<endl;
}