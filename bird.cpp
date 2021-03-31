#include<iostream>

using namespace std;

enum birdType {PEACOCK, SPARROW, CANARY, PARROT, PENGUIN, OSTRICH, EAGLE
                ,CARDINAL, HUMMINGBIRD};

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
    birdType bird;
    bird = CANARY;
    bird = static_cast<birdType>(bird+1);
    bird = static_cast<birdType>(bird-1);
    displayBirdType(bird);
    cout<<endl;
    bird = getBirdType();
    displayBirdType(bird);
}