#include<iostream>

using namespace std;

//A function to get an input from the user, using pass-by-reference.
void getInput(double& year_n, double& year_o, double& year_t){
    cout<<"Please input the current price: ";
    cin>> year_n;
    cout<<"Please input the price a year ago: ";
    cin>> year_o;
    cout<<"Please input the price two years ago: ";
    cin>> year_t;
}

//Calculate the inflation rate by getting the prices from the current year,
//previous year, and last two years. Includes a pass-by-reference and pass-by-value.
void calculateRate(double year_n, double year_o, double year_t,
                double& inf_rate1, double& inf_rate2, double& inf_rateall){
    inf_rate1 = (year_n - year_o)/year_o;
    inf_rate2 = (year_o - year_t)/year_t;
    inf_rateall = (year_n-year_t)/year_t;
    }

//A function to output the results of the computations from the function, 
//calculateRate().
void outputResults(double inf_rate1,double inf_rate2, double overall){
    cout<<"Current Inflation from a year ago: "<<inf_rate1*100<<"%."<<endl;
    cout<<"Current Inflation from two years ago: "<<overall*100<<"%."<<endl;
    cout<<"Last Year Inflation: "<<inf_rate2*100<<"%.";
}

//Calls the function definitions above, to get an input from the user, 
//calculate the inflation rate, and output the results. All of the procedures
//are found in the functions 'getInput','calculateRate','outputResults'.
int main(){
    double yearnow, yearone, yeartwo, inflation_rate1, 
        inflation_rate2,overall_infl;
    getInput(yearnow,yearone, yeartwo);
    calculateRate(yearnow,yearone,yeartwo,inflation_rate1, inflation_rate2,overall_infl);
    outputResults(inflation_rate1,inflation_rate2, overall_infl);
}