    #include <iostream>
    using namespace std;


    //A function that will reversed the digits
    //of an integer. It gets the first digit at
    //the rightmost and add to an integer variable.
    //Divide the number by 10 to get the next place.
    int reverseDigit(int number){
        int rev=0, remainder;
        while(number != 0) {
            rev = rev*10 + number%10;
            number/=10;
        }
        return rev;
    }

    int main() {
        //Declare a variable of type integer to store
        //the input from the user.
        int number;
        cout<<"Please input an integer: ";
        cin>>number;
        
        //Call the function reverseDigit(int) to get
        //the reversed versino of the number.
        cout<<"Reversed: "<<reverseDigit(number);

        return 0;
    }