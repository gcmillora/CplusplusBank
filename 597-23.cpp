#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    double salary[5] = {25000, 36500, 85000, 62500, 97000};
    double raise = 0.03;
    cout << fixed << showpoint << setprecision(2);
    for (int i = 0; i < 5; i++)
        cout << (i + 1) << " " << salary[i] << " "
            << salary[i] * raise << endl;
}