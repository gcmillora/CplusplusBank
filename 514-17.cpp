#include<iostream>
#include<string>

using namespace std;

int main(){
    string str= "Regular exercise can reduce health insurance cost.";
    string str1;
    string str2 = "low fat diet";
    string newStr;
    string::size_type index;
    index = str.find("can");
    str1 = str.substr(0,index-1);
    cout<<str1<<endl;
    newStr = str1+" and "+str2;
    cout<<newStr<<endl;
    cout<<newStr.length()<<endl;

    cout<<str1.find("ex")<<endl;
    cout<<str2.find('d')<<endl;

    index = str.find("health");
    newStr = str.substr(index,17);
    
    cout<<newStr<<endl;
    cout<<newStr.substr(7,14)<<endl;
    index = str.find("cost");
    cout<<str.replace(index,4,"$$$$") <<endl;

    str = "$ocial Nedia!!";
    cout<<str<<endl;
    cout<<str.length()<<endl;

    str[0] = 'S';
    index = str.find('N');
    str[index] = 'M';
    cout<<str<<endl;
    return 0;

}