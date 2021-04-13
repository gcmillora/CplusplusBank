#include<iostream>

using namespace std;

//Definition of an enum type, birdType
//with the following values.
enum birdType {PEACOCK, SPARROW, CANARY, PARROT, PENGUIN, OSTRICH, EAGLE
                ,CARDINAL, HUMMINGBIRD};

//A function to display the value of a variable 
//of type birdType.
void displayBirdType(birdType bird){
    if(bird==PEACOCK) cout<<"PEACOCK";
    if(bird==SPARROW) cout<<"SPARROW";
    if(bird==CANARY) cout<<"CANARY";
    if(bird==PARROT) cout<<"PARROT";
    if(bird==PENGUIN) cout<<"PENGUIN";
    if(bird==OSTRICH) cout<<"OSTRICH";
    if(bird==EAGLE) cout<<"EAGLE";
    if(bird==CARDINAL) cout<<"CARDINAL";
    if(bird==HUMMINGBIRD) cout<<"HUMMINGBIRD";
}

//A function that will get an input from the user
//on what bird type and store the value inside a
//variable of birdType. Return a data of type
//birdType.
birdType getBirdType(){
    string type;
    birdType bird;
    while(1){
        cout<<"[PEACOCK]\t[SPARROW]\n";
        cout<<"[CANARY]\t[PARROT]\n";
        cout<<"[OSTRICH]\t[PENGUIN]\n";
        cout<<"[EAGLE]\t[CARDINAL]\n";
        cout<<"[HUMMINGBIRD]\t"<<endl;
        cout<<"Please input the type of the bird: ";
        cin>>type;
        if(type=="PEACOCK"){
            bird = PEACOCK;
            return bird;
        }
        else if(type=="SPARROW"){
            bird = SPARROW;
            return bird;
        }
        else if(type=="CANARY"){
            bird = CANARY;
            return bird;
        }
        else if(type=="PARROT"){
            bird = PARROT;
            return bird;
        }
        if(type=="OSTRICH"){
            bird = OSTRICH;
            return bird;
        }
        else if(type=="PENGUIN"){
            bird = PENGUIN;
            return bird;
        }
        if(type=="EAGLE"){
            bird = EAGLE;
            return bird;
        }
        else if(type=="CARDINAL"){
            bird = CARDINAL;
            return bird;
        }
        else if(type=="HUMMINGBIRD"){
            bird = HUMMINGBIRD;
            return bird;
        }
        else{
            continue;
        }
    }
}
int main(){
    birdType bird = CARDINAL;
    cout<<endl;
    cout<<"Type of Bird: ";
    displayBirdType(bird);
}