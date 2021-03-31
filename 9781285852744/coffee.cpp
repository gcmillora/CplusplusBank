#include<iostream>

using namespace std;

const double s_price = 1.75;
const double m_price = 1.90;
const double l_price = 2.00;
const int small = 9;
const int medium = 12;
const int large = 15;

void display(){
    cout<<"Jason's Coffee Shop"<<endl;
    cout<<endl;
    cout<<"[1] Sell Coffee"<<endl;
    cout<<"[2] Sold Information"<<endl;
    cout<<"[3] Total Amount Coffee Sold"<<endl;
    cout<<"[4] Total Money Made"<<endl;
    cout<<"[0] End Program"<<endl;
    cout<<endl;
}

void sellCoffee(double& totalprice, int& totalcoffee,
                        int& s,int& m, int& l){
    int choice=0,cups;
    double price=0;
    cout<<"[1] Small Cup (9oz) - $1.75"<<endl;
    cout<<"[2] Medium Cup (12oz) - $1.90"<<endl;
    cout<<"[3] Large Cup (15oz) - $2.00"<<endl;
    cout<<"Choice: ";
    cin>>choice;
    cout<<"How many cups?: ";
    cin>>cups;
    if(choice==1){
        s+=cups;
        price = s_price*cups;
        totalcoffee+=small*cups;
    }
    else if(choice ==2){
        m+=cups;
        price = m_price*cups;
        totalcoffee+= medium*cups;
    }
    else if(choice==3){
        l+=cups;
        price = l_price*cups;
        totalcoffee+-large*cups;
    }
    cout<<endl;
    cout<<"Total Number of Cups: "<<cups<<endl;
    cout<<"Total Amount: "<<price<<endl;
    cout<<endl;
    totalprice += price;
}

void soldInfo(int s,int m,int l){
    cout<<"Number of Cups Sold"<<endl;
    cout<<endl;
    cout<<"Small Cups 9oz: "<<s<<endl;
    cout<<"Medium Cups 12oz: "<<m<<endl;
    cout<<"Large Cups 15oz: "<<l<<endl;
    cout<<endl;
}

void coffeeSold(int coffee){
    cout<<"Total Amount of Coffee Sold: "<<
        coffee<<endl;
    cout<<endl;
}

void moneyMade(int money){
    cout<<"Total Amount of Money Made: "<<
        money<<endl;
    cout<<endl;
}

int main(){
    double total_price=0;
    int total_coffee=0;
    int size_s=0,size_m=0,size_l=0;
    int choice;
    while(1){
        display();
        cout<<"Choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                sellCoffee(total_price,total_coffee,
                          size_s,size_m,size_l);
                          break;
            case 2:
                soldInfo(size_s,size_m,size_l);
                break;
            case 3:
                coffeeSold(total_coffee);
                break;
            case 4:
                moneyMade(total_price);
                break;
            case 0:
                return 0;
                break;
            default:
                cout<<"Invalid input!"<<endl;
        }
    }

}