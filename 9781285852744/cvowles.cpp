#include<iostream>

using namespace std;

//A function that has two parameters, the input string
//and the character to count. Traverses the string, and
//increments the count of that character vowel. Returns
//the total count.
int getCount(string inp, char vowel){
    int count=0;
    for(int ctr=0;ctr<inp.length();ctr++){
        if(inp.at(ctr)==vowel){
            count++;
        }
    }
    return count;
}

//A function that assigns the return value from the function
//getCount to the appropriate variable.
void getVowelCount(string inp, int& a,int& e,int& i,int& o,int& u){
    a = getCount(inp,'a');
    e= getCount(inp,'e');
    i = getCount(inp,'i');
    o = getCount(inp,'o');
    u = getCount(inp,'u');
}

int main(){
    //Declare the variables needed for the problem.
    int a=0,e=0,i=0,o=0,u=0;  
    string input;
    cout<<"Please enter a string:";
    cin>>input;
    getVowelCount(input,a,e,i,o,u);
    cout<<"a: "<<a<<endl;
    cout<<"e: "<<e<<endl;
    cout<<"i: "<<i<<endl;
    cout<<"o: "<<o<<endl;
    cout<<"u: "<<u<<endl;
}