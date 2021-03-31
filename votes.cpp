#include<iostream>
#include<iomanip>
using namespace std;

//A function that will get the index of the largest
//value in an integer array, assuming that the last
//largest value is the index that will be returned.
int lastLargestIndex(int array[], int length){
    int temp = array[0];
    int index = 0;
    for(int ctr=0;ctr<length;ctr++){
        if(temp<array[ctr]) index = ctr;
    }
    return index;
}

int main(){
    cout << fixed << showpoint<<setprecision(2);
    string candidates[5];
    int votes[5];
    float total_votes[5];
    double sum=0;
    int test[0..99];

    //A for-loop that will get the candidates names
    //from the user and store it in the array, candidates[5].
    cout<<"Please enter five candidates: "<<endl;
    for(int ctr=0;ctr<5;ctr++){
        cout<<"Candidate #"<<ctr+1<<": ";
        cin>>candidates[ctr];
    }

    //A for-loop that will get the votes for each candidate
    //from the user and store it in the array, votes[5];
    cout<<"Please enter the number of votes: "<<endl;
    for(int ctr=0;ctr<5;ctr++){
        cout<<"Candidate #"<<ctr+1<<": ";
        cin>>votes[ctr];
        sum+=votes[ctr];
    }

    //A for-loop that will compute the percentage of total votes
    //for each candidate and store it in the array, total_votes[5].
        for(int ctr2=0;ctr2<5;ctr2++){
            total_votes[ctr2] = votes[ctr2]/sum*100;
        }

    int winner = lastLargestIndex(votes,5);
    //A for-loop that will output the candidate name, votes received, and
    //percentage of votes from the total votes.
    cout<<"Candidate\tVotes Received\t% of Total Votes"<<endl;
    for(int ctr=0;ctr<5;ctr++){
        cout<<candidates[ctr]<<"\t\t\t"<<votes[ctr]<<"\t\t"<<total_votes[ctr];
        cout<<endl;
    }
    cout<<"Total"<<"\t\t\t"<<(int)sum<<endl;
    cout<<endl<<"The winner of the Election is "<<candidates[winner]<<".";
}
