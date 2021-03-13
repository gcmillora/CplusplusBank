#include<iostream>
#include<cmath>

using namespace std;

//A function to compute for the periodic payment,
//included parameters are the loan, rate, m or number
//of payments in a year, and t, the number of years to pay.
double computePeriodic(double loan, double r, int m, int t){
    double i = r/m;
    double per = (loan*i) / (1 - pow((1+i),(-1*m*t)));
    return per;
}

//A function to compute for the remaining unpaid loan balance,
//inlcuded parameters are the loan, rate, m or number of payments
//t, the number of years to pay and k, the number of payments done.
double loanBalance(double loan, double r, int m, int t, double periodic,int k){
    double i = r/m;
    double power = -1*(m*t-k);
    double numerator = 1 - pow((1+i),power);
    return periodic*(numerator/i);
}


int main(){
    //Declare the necessary variables needed for the problem.
    double loan, r, periodic;
    int m,t,choice,k;
    cout<<"A program that will compute for the periodic"
        <<"payments."<<endl;
    //A while loop to continue executing the statements under
    //until the user decides to stop.
    while(1){
        cout<<endl<<"[1] Compute Periodic Payment";
        cout<<endl<<"[2] Compute for the unpaid loan balance";
        cout<<endl<<"[0] End Program"<<endl;
        cin>>choice;
        //A switch statement to evaluate the choice inputted
        //by the user.
        switch(choice){
            case 1:{
                cout<<"Please input the loan amount: ";
                cin>> loan;
                cout<<"Please input the interest rate per year: ";
                cin>> r;
                cout<<"Please input the number of payments in a year: ";
                cin>> m;
                cout<<"Please input how many years to pay: ";
                cin>> t;
                periodic = computePeriodic(loan,r,m,t);
                cout<<"Periodic Payment: "<<periodic;
            }
                break;
            case 2: {
                cout<<"Please how many payments are done: ";
                cin>>k;
                double balance = loanBalance(loan,r,m,t,periodic,k);
                cout<<"Unpaid Balance: "<<balance;
                break;
            }
            case 0:
                return 0;
                break;
            default:
                cout<<"Invalid input!";
            }
    }
    return 0;
}