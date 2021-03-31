#include<iostream>
#include<iomanip>
#include <fstream>

using namespace std;

const int N = 20;

void initialize(int& zeroCount, int& oddCount, int& evenCount);
bool getNumber(int& num, ifstream&,ofstream&);
void classifyNumbers(int num, int& zeroCount, int& oddCount, 
                                                int& evenCount);
void printResults(int zeroCount, int oddCount, int evenCount, double sum,
                    int count, ofstream& writer);

int main(){
    int counter,number,zeros,odds,evens;
    double sumOf=0;
    bool check;
    initialize(zeros,odds,evens);

    //Create an outstream and instream classes to operate
    //on files.
    ofstream writer("results.txt");
    ifstream reader("inputs.txt");
    reader.open("input.txt");
    if (!reader) {
        cout << "Unable to open file";
        exit(1);
    }
    do {
            check = getNumber(number,reader,writer);
            if(check){
                classifyNumbers(number,zeros,odds,evens);
                sumOf += number;
                counter++;
            }
        } while(check);
    writer<<endl<<endl<<endl;
    printResults(zeros,odds,evens,sumOf,counter,writer);
    return 0;
}

void initialize(int& zeroCount, int& oddCount, int& evenCount){
    zeroCount=0;
    oddCount=0;
    evenCount=0;
}

bool getNumber(int& number,ifstream& reader,ofstream& writer){
    static int count = 0;
    if(reader>>number ){
        writer << number << " ";
        count++;
        //If 10 numbers are read, create a new line.
        if(count == 10){
            writer<<endl;
            count = 0;
        }
        return true;
        } 
    else {
        if(count != 1)
          writer<<endl;
        return false;
        }
}

void classifyNumbers(int num, int& zeroCount, int&oddCount,
                        int& evenCount){
    switch(num%2){
        case 0:
            evenCount++;
            if(num==0) zeroCount++;
            break;
        case 1:
        case -1:
           oddCount++;
    }
}

void printResults(int zeroCount, int oddCount, int evenCount, 
                    double sum, int count, ofstream& writer){
    double average =sum/count;
    writer<<"There are "<<evenCount<<" evens, "
    <<"which includes "<<zeroCount<<" zeroes"
    <<endl;
   writer<<"The total count of the numbers is "
        <<count<<"."<<endl;
    writer<<"The sum of the numbers is "<<sum<<"."<<endl;
    writer<<"The average of the numbers is "<<average<<"."<<endl;
    writer<<"The number of odd numbers is: "<<oddCount
        <<endl;
}
