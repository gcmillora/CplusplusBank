#include<iostream>

using namespace std;

//A function to return the number of lowercase vowels
//in a string. Accepts a variable of type string as its
//parameters.
int getCount(string inp, int& a, int& e,int& i,int& o,int& u){
    int count=0;

    //Checks if the character at index 'ctr' is equal to a
    //lowercase vowel, a,e,i,o,u.
    for(int ctr=0;ctr<inp.length();ctr++){
        switch(inp.at(ctr)){
            case 'a':
                a++;
                break;
            case 'e':
                e++;
                break;
            case 'i':
                i++;
                break;
            case 'o':
                o++;
                break;
            case 'u':
                u++;
                break;
            default:
                continue;
            
        }
    }
    return count;
}

int main(){
    //Declare a variable of type string to store the input
    //from the user.
    string input;
    int a=0,e=0,i=0,o=0,u=0;
    cout<<"Please input a string: ";
    cin>>input;

    //Call the function getCount(string) and store the value
    //in a variable of type integer.
    int num_vowels = getCount(input,a,e,i,o,u);
    cout<<"a: "<<a<<endl;
    cout<<"e: "<<e<<endl;
    cout<<"i: "<<i<<endl;
    cout<<"o: "<<o<<endl;
    cout<<"u: "<<u<<endl;
    return 0;
}