#include<iostream>

using namespace std;

void tryMe(int& v){
    static int num = 2;
    if(v%2==0){
        num++;
        v = v+3;
    }
    else{
        num--;
        v = v+5;
    }
    cout<< v << ", "<<num<<endl;
}

int main(){
    int x = 8;
    for(int count = 1; count<5;count++){
        tryMe(x);
    }
    return 0;

}