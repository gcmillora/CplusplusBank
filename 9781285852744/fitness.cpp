#include<iostream>

using namespace std;

//A function of type void to display the offers and
//discounts of the fitness center.
void display(){
    cout<<"Fitness Center"<<endl<<endl;
    cout<<"Available Discounts: "<<endl;
    cout<<"1.) 30% discount on Senior Citizens"<<endl;
    cout<<"2.) 15% discount on 12+ months paid"<<endl;
    cout<<"3.) 20% discount on each session for 5+"<<
            "personal sessions"<<endl;
}

//A function to calculate the total price minus the total
//discount. Includes the conditions set by the problem to
//calculate for the total discount. 
double calculatePrice(double& cmonths,double& csessions,
                    double& pmonths, double& psessions,
                    bool senior){
    double discount = 0;
    double total_price = 0;
    double month_cost=0, session_cost=0;
    month_cost = cmonths*pmonths;
    session_cost = csessions*psessions;
    if(pmonths>=12)
        discount+= month_cost*0.15;
    if(psessions>=5)
        discount+= session_cost*0.20;
    if(senior)
        discount+= (month_cost+session_cost)*0.30;
    double total = session_cost+month_cost-discount;
    return total;
    }

//A function to get the input from the user and store to
//the appropriate variables. Uses a pass-by-reference to
//store the inputs.
void getData(double& cmonths,double& csessions,
                    double& pmonths, double& psessions,
                    bool& senior){
    cout<<"Cost per month: ";
    cin>> cmonths;
    cout<<"Cost per session: ";
    cin>> csessions;
    cout<<"Number of paid months: ";
    cin>>pmonths;
    cout<<"Number of paid sessions: ";
    cin>>psessions;
    cout<<"Are you a senior? (Y/N): ";
    char choice;
    cin>>choice;
    if(choice=='Y') senior = true;

}
int main(){
    double cost_months,cost_sessions;
    double paid_months, paid_sessions;
    bool is_Senior = false;
    double total_price;
    int choice=0;
    while(1){
        cout<<"[1] Offers/Discounts"<<endl;
        cout<<"[2] Calculate Price"<<endl;
        cout<<"[3] End Program"<<endl;
        cout<<"Please enter your choice:";
        cin>>choice;
        switch(choice){
            case 1:
                display();
                cout<<endl;
                break;
            case 2:
                getData(cost_months,cost_sessions,
                paid_months,paid_sessions,is_Senior);
                total_price = calculatePrice(cost_months,cost_sessions,
                paid_months,paid_sessions,is_Senior);
                cout<<"Total Price: "<<total_price<<endl;
                cout<<endl;
                break;
            case 3:
                return 0;
                break;
            default:
                cout<<"Invalid input!";
                cout<<endl;
        }
    }
}