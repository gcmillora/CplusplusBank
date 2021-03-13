#include<iostream>

using namespace std;

//A function that will get two random
//values, die_1 and die_2, from 1 - 6,
//and count how many times until the
//desired sum is reached.
int rollDice(int number){
    int die_1, die_2;
    int sum, rollCount =0;
    do{
        die_1 = rand()%6+1;
        die_2 = rand()%6+1;
        sum = die_1+die_2;
        rollCount++;
    }while(sum!=number);
    return rollCount;
}

int main(){
    int choice;
    //A while loop with the condition while(1) to
    //continue the program until the user decides
    //to stop.
    while(1){
        cout<<"[1] Roll a Dice\n[2] End"<<endl;
        cin>>choice;
        //Switch statement to do the appropriate action
        //after a choice is inputted.
        switch(choice){
            case 1:
                int number;
                cout<<"Please input the sum of the two dice: ";
                cin>>number;

                //Call the function rollDice(int).
                cout<<"The number of times the dice are rollted to "
                    <<"get the sum of "<<number<<" = " <<
                                    rollDice(number)<<endl;
                break;
            case 2:
                cout<<"Ending program."<<endl;
                return 0;
                break;
            default:
                cout<<"Invalid input!"<<endl;
    }
 }
}