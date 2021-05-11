#include<iostream>

using namespace std;

enum currencyType {DOLLAR,POUND,FRANK,LIRA,MARK};

int main(){
    currencyType currency; 
    currency = DOLLAR;
    cin >> currency;
    currency = static_cast<currencyType>(currency+1);
    for(currency=DOLLAR;currency<=MARK;currency++)
        cout<<"*";
}