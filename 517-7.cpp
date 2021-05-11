#include<iostream>

using namespace std;


void displayMenu(){
    cout<<"[1] Input Data"<<endl;
    cout<<"[2] Add Fractions"<<endl;
    cout<<"[3] Subtract Fractions"<<endl;
    cout<<"[4] Divide Fractions"<<endl;
    cout<<"[5] Multiply Fractions"<<endl;
    cout<<"[0] End Program"<<endl;
}
void getData(int& num1,int& den1,int& num2, int& den2){
    cout<<"Numerator 1: ";
    cin>>num1;
    cout<<"Denominator 1: ";
    cin>>den1;
    cout<<"Numerator 2: ";
    cin>>num2;
    cout<<"Denominator 2: ";
    cin>>den2;
}

void addFractions(int num1,int den1,int num2,int den2, int& rnum, int& rden){
    rden = den1*den2;
    rnum = (num1*den2) + (num2*den1);
}

void subtractFractions(int num1,int den1,int num2,int den2, int& rnum, int& rden){
    rden = den1*den2;
    rnum = (num1*den2) - (num2*den1);
}

void multiplyFractions(int num1,int den1,int num2,int den2, int& rnum, int& rden){
    rden = den1*den2;
    rnum = num1*num2;
}

void divideFractions(int num1,int den1,int num2,int den2, int& rnum, int& rden){
    rden = num2*den1;
    rnum = num1*den2;
}

int main(){
    int num_1,num_2;
    int den_1,den_2;
    int rnum,rden;
    int option;
    while(1){
        displayMenu();
        cout<<"\nChoice: ";
        cin>> option;   
        switch(option){
            case 1:
                getData(num_1,den_1,num_2,den_2);
                break;
            case 2:
                cout<<"Adding Fractions...\n";
                cout<<num_1<<"/"<<den_1<<" + "<<num_2<<"/"<<den_2;
                addFractions(num_1,den_1,num_2,den_2,rnum,rden);
                cout<<" = "<<rnum<<"/"<<rden;
                break;
            case 3:
                cout<<"Subtracting Fractions...\n";
                cout<<num_1<<"/"<<den_1<<" - "<<num_2<<"/"<<den_2;
                subtractFractions(num_1,den_1,num_2,den_2,rnum,rden);
                cout<<" = "<<rnum<<"/"<<rden;
                break;
            case 4:
                cout<<"Multiplying Fractions...\n";
                cout<<num_1<<"/"<<den_1<<" * "<<num_2<<"/"<<den_2;
                multiplyFractions(num_1,den_1,num_2,den_2,rnum,rden);
                cout<<" = "<<rnum<<"/"<<rden;
                break;
            case 5:
                cout<<"Dividing Fractions...\n";
                cout<<num_1<<"/"<<den_1<<" / "<<num_2<<"/"<<den_2;
                divideFractions(num_1,den_1,num_2,den_2,rnum,rden);
                cout<<" = "<<rnum<<"/"<<rden;
                break;
            case 0:
                cout<<"Ending program...";
                return 0;
                break;
            default:
                cout<<"Please enter a valid option."<<endl;
        }
        cout<<endl;
    }

}