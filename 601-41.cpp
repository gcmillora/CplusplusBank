#include<iostream>

using namespace std;

int main(){
    const int CAR_TYPES = 5;
    const int COLOR_TYPES = 6;

    double sales[CAR_TYPES][COLOR_TYPES];
    double sales_types[CAR_TYPES];
    double sales_color[COLOR_TYPES];
    for(int ctr=0;ctr<5;ctr++){
        sales_types[ctr] = 0;
        for(int ctr2=0;ctr2<6;ctr2++){
            sales_types[ctr] += sales[ctr][ctr2];
        }
    }

    for(int ctr=0;ctr<6;ctr++){
        sales_color[ctr] = 0;
        for(int ctr2=0;ctr2<5;ctr2++){
            sales_color[ctr] += sales[ctr2][ctr];
        }
    }
    return 0;
}
