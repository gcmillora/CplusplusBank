#include<iostream>
#include<string>

namespace rate{
    const double RATE_MIN  = 0.2;
    const double BASE_RATE = 10;
    const double PRM_RATE = 25;
    const double DAY_MIN  = 0.1;
    const double NIGHT_MIN = 0.05;
}

using namespace std;
using namespace rate;

int main(){
    string account;
    char accountType;
    double minutes,n_minutes, total;
    cout<<"Account Number:";
    getline(cin,account);
    cout<<"Account Type (R or P): ";
    cin>>accountType;
    
    if(accountType=='R'){
        cout<<"Minutes of call: ";
        cin>>minutes;
        if(minutes<50) total = BASE_RATE;
        else total = BASE_RATE + (minutes-50)*RATE_MIN;
        cout<<"\nReceipt:\n";
        cout<<"Account Number: "<<account<<endl;
        cout<<"Account Type: "<<accountType<<endl;
        cout<<"Total Minutes: "<<minutes<<endl;
        cout<<"Cost: "<<total<<endl;
    }
    else{
        cout<<"Minutes of call (Day): ";
        cin>>minutes;
        cout<<"Minutes of call (Night): ";
        cin>>n_minutes;

        total = PRM_RATE;
        if(minutes>75)
            total += (minutes-75) * DAY_MIN;
        if(n_minutes>100)
            total += (minutes-100) * NIGHT_MIN;
        cout<<"\nReceipt:\n";
        cout<<"Account Number: "<<account<<endl;
        cout<<"Account Type: "<<accountType<<endl;
        cout<<"Total Minutes: "<<minutes<<endl;
        cout<<"Cost: "<<total<<endl;
    }
    return 0;

}