#include<iostream>

using namespace std;

void displayMenu(){
    cout<<"[1] Choose a seat"<<endl;
    cout<<"[2] Check available seats"<<endl;
    cout<<"[3] Exit"<<endl;
}
void displayTicketType(){
    cout<<"[1] First Class (Rows 1 and 2)"<<endl;
    cout<<"[2] Business Class (Rows 3 and 7)"<<endl;
    cout<<"[3] Economy Class (Rows 8 and 13)"<<endl;
}

void bookSeat(int row,int column, char seats[][6]){
    if(seats[row-1][column-1]=='X'){
        cout<<"Sorry, this seat is available."<<endl;
        cout<<"Check available seats in the menu."<<endl;
    }
    else{
        cout<<endl<<endl;
        cout<<"Seat reserved. Have a safe flight."<<endl;
        cout<<"Seating Assignment: ";
        cout<<"ROW"<<row<<" COLUMN"<<column<<endl;
        seats[row-1][column-1] = 'X';
    }
}

void getSeat(char seats[][6]){
    displayTicketType();
    int choice=0;
    int row=0,column = 0;
    cout<<"Please input the ticket type: ";
    cin>>choice;
    if(choice<=0||choice>3){
        cout<<"Please input a valid ticket type."<<endl;
        cout<<"Going back to the Menu!";
    }
    cout<<"Please input which row: ";
    cin>>row;
    cout<<"Please input which column: ";
    cin>>column;
    if(choice==1){
        if(row<1||row>2) cout<<"Invalid row/column."<<endl;
        else bookSeat(row,column,seats);
    }
    else if(choice==2){
         if(row<3||row>7) cout<<"Invalid row/column."<<endl;
         else bookSeat(row,column,seats);
    }
    else if(choice==3){
         if(row<8||row>13) cout<<"Invalid row/column."<<endl;
         else bookSeat(row,column,seats);
    }
}


void displaySeat(char seats[][6]){
    for(int ctr=0;ctr<13;ctr++){
        cout<<"Row "<<ctr+1<<":\t";
        for(int ctr2=0;ctr2<6;ctr2++){
            cout<<seats[ctr][ctr2]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    char seatAssign[13][6]={
    {'*','*','X','*','X','X'},
    {'*','X','*','X','*','X'},
    {'*','*','X','X','*','X'},
    {'X','*','X','*','X','X'},
    {'*','X','*','X','*','*'},
    {'*','X','*','*','*','X'},
    {'X','*','*','*','X','X'},
    {'*','X','*','X','X','*'},
    {'X','*','X','X','*','X'},
    {'*','X','*','X','X','X'},
    {'*','*','X','*','X','*'},
    {'*','*','X','X','*','X'},
    {'*','*','*','*','X','*'}};
    int choice = 0;
    while(1){
        displayMenu();
        cout<<"Choice: ";
        cin>> choice;
        switch(choice){
            case 1: 
                getSeat(seatAssign);
                break;
            case 2:
                displaySeat(seatAssign);
                break;
            case 3:
                cout<<"Program exit!";
                return 0;
                break;
            default:
                cout<<"Incorrect choice!"<<endl;
        }
    }
    
}