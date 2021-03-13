#include<iostream>

using namespace std;

//A function that computes for the regular
//bill. The conditions are based on Programming
//Exercise 14 from Chapter 4.
double regularBill(int mins){
    if(mins<50) return 10;
    else return 10+((mins-50)*0.20);
}

//A function that computes for the premium
//bill. The conditions are based on Programming
//Exercise 14 from Chapter 4.
double premiumBill(int day, int night){
    double dayBill, nightBill;
    if(day>75)
        dayBill = (day-75)*0.10;
    
    if(night>100)
        nightBill = (night-100)*0.05;
    
    return 25+dayBill+nightBill;
}

int main(){
    //Declare the variables needed for the problem,
    //account number, code either R,r or P,p and the
    //bill due.
    int account_number;
    char code;
    double bill;
    cout<<"Please input your account number: ";
    cin >> account_number;
    cout << "Choose the type of service (R - Regular, P- Premium) : ";
    cin>> code;

    //Use the toupper function to convert all character input to upper case.
    //Call the appropriate function to compute for the bill and output the
    //Account Number, Type of Service, and Amount Due.
    code = toupper(code);
    switch(code){
        case 'R':
            int r_mins;
            cout<<"Please input how many minutes the service was used: ";
            cin>> r_mins;
            bill = regularBill(r_mins);
            cout<<"Account Number: "<<account_number<<endl;
            cout<<"Type of Service: Regular"<<endl;
            cout<<"Amount Due: "<<bill<<endl;
            break;
        case 'P':
            int d_mins, n_mins;
            cout<<"Please input how many minutes (day) the service was used:";
            cin>> d_mins;
            cout<<"Please input how many minutes (night) the service was used: ";
            cin>> n_mins;
            bill = premiumBill(d_mins,n_mins);
            cout<<"Account Number: "<<account_number<<endl;
            cout<<"Type of Service: Premium"<<endl;
            cout<<"Amount Due: "<<bill<<endl;
            break;
        default:
            cout<<"Invalid input!";
}
return 0;
}