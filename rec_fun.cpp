#include<iostream>

using namespace std;

void recFun(int x){
    if (x > 0){
        cout << x % 10 << " ";
        recFun(x / 10);
    }
    else if (x != 0)
        cout << x << endl;
}

int main(){
    recFun(-85);
    return 0;
}