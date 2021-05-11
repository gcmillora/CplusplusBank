#include<iostream>

using namespace std;

    int main(){
        string str1,str2;

        cin>> str1 >> str2;
        if (str1==str2)
            cout<<str1+'!'<<endl;
            else if(str1>str2)
                cout<<str1+" > " + str2 << endl;
                else
                    cout<<str1+" < "+ str2 <<endl;
        
    }