#include<iostream>

using namespace std;

//Function prototypes as specified in
//Example 13 of Chapter 6.
void getScore(int& score);
char calculateGrade(int score);

int main(){
    int courseScore;
    cout<<"Line 1: Based on the course score,\n"
    << "this program computes the course grade."<<endl<<endl;
    getScore(courseScore);
    char grade = calculateGrade(courseScore);
      cout<<"Line 7: Your grade for the course is "<<grade<<".";
}

void getScore(int& score){
    cout<<"Line 4: Enter course score: "<<endl;
    cin>>score;
    cout<<endl<<"Line 6: Course score is "<< score<<endl;
}

//Changed the function printGrade to calcualteGrade
//to return a value rather than a void function and printing
//the output.
char calculateGrade(int cScore){
    if(cScore>= 90) return 'A';
    else if(cScore>= 80) return 'B';
    else if(cScore>= 70) return 'C';
    else if(cScore>= 60) return 'D';
    else
        return 'F';
}