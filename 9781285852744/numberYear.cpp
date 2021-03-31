#include<iostream>
#include <sstream>  

using namespace std;

int getDay(int arr[]){
    int month = arr[0];
    int day = arr[1];
    int year = arr[2];
    //Loop to add all the days of the month before the month
    //inputted by the user, for example, all months before 
    //December or month number 12.
    for(int ctr=0;ctr<month-1;ctr++){
        if(ctr==0||ctr==2||ctr==4||ctr==6||ctr==7||
                ctr==9||ctr==11) day += 31;
        else if(ctr==1) day+= 28;
        else day+=30;
    }
    //Check if the year is a leap year, if yes then add a day
    //if the month exceeds February or month number 2.
    if((year%400==0&&year%100==0)||(year%4==0 && year%100!=0)){
            if (month>2){
                day++;
            }
        }
    return day;
}

int main(){
    string date;
    int dte[3];
    int pos = 0,count=0;
    cout<<"Please input the date: ";
    cin>>date;
    
    //Omit the character '-' of the date format and store
    //the day, month and year into an integer array. Use
    //a delimeter to omit a character.
    string delimiter = "-";
    string token;
    while ((pos = date.find(delimiter)) != string::npos) {
        token = date.substr(0, pos);
        dte[count] = stoi(token);
        date.erase(0, pos + delimiter.length());
        count++;
    }
    dte[count] = stoi(date);
    cout<<"That is Day "<<getDay(dte)<<" in that year."<<endl;
    return 0;
}