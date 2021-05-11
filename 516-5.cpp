#include<iostream>

using namespace std;

void getData(string& status, int& children, 
        double& salary, double& pension){
    char choice;
    cout<<"Are you married? (Y/N)";     
    cin>>choice;
    switch(choice){
        case 'Y':
        case 'y':
            status = "Married";
            break;
        case 'N':
        case 'n':
            status = "Single";
            break;
        default:
            cout<<"Invalid Answer";
            return;
    } 
    if(status == "Married"){
        cout<<"How many children do you have?";
        cin>>children;
    }
    cout<<"What is your gross salary (if married, please enter combined salary)?";
    cin>>salary;
    cout<<"Pleae input the percentage of gross income contributed to a pension fund: ";
    cin>>pension;
}

void taxAmount(int children,double salary,
        double pension, double& tax){
    double pension_plan = (pension/100)*salary;
    double exemption;
    if(children==0){
        exemption = 4000+1500;
    }
    else{
        exemption = 7000+(1500*(2+children));
    }
    double tax_income = salary - exemption - pension_plan;
    if(tax_income<=15000) tax = 0.15*tax_income;
    else if(tax_income>15000&&tax_income<=40000) 
            tax = 2250 + .25*tax_income/15000;
    else tax =8460+.35*tax_income/40000;
}
int main(){
    string maritalstatus;
    int no_children=0;
    double gross_salary;
    double pct_pension;
    double tax;
    getData(maritalstatus,no_children,gross_salary,pct_pension);
    taxAmount(no_children,gross_salary,pct_pension,tax);
    cout<<"Computed Federal Tax: "<<tax;

}