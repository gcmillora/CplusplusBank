#include<iostream>

using namespace std;

//A function that will set the elements of
//a single dimensional array to 0.
void setZero(int array[],int size){
    for(int ctr=0;ctr<size;ctr++){
        array[ctr] = 0;
    }
};

//A function to input the elements into the array
//alpha[20].
void inputArray(int array[]){
    for(int ctr=0;ctr<20;ctr++){
        cout<<"Index ["<<ctr<<"]: ";
        cin>>array[ctr];
    }
}

//A function that will initialize the elements of the
//array beta[] to two times the corresponding element
//in array alpha[].
void doubleArray(int beta_arr[],int alpha_arr[]){
    for(int ctr=0;ctr<20;ctr++){
        beta_arr[ctr] = 2*alpha_arr[ctr];
    }
}

//A function that will copy the elements of gamma to the
//first row of elements in the two dimensional array, 
//inStockp[] and set the remaining elements to 3 times
//the element of the corresponding previous row.
void copyGamma(int gamma_arr[], int stock[][4]){
    for(int ctr1=0;ctr1<10;ctr1++){
        for(int ctr2=0;ctr2<4;ctr2++){
            if(!ctr1)
                stock[ctr1][ctr2] = gamma_arr[ctr2];
            else
                stock[ctr1][ctr2] = 3*stock[ctr1-1][ctr2]; 
        }
    }
}

//A function to copy the elements of the arrays alpha[] and beta[]
//to the two dimensional array, inStock[].
void copyAlphaBeta(int alpha_arr[],int beta_arr[],int stock[][4]){
    int alp_ctr=0;
    int beta_ctr=0;
    for(int ctr=0;ctr<10;ctr++){
        for(int ctr2=0;ctr2<4;ctr2++){
            if(alp_ctr!=20){
                stock[ctr][ctr2] = alpha_arr[alp_ctr];
                alp_ctr++;
            }
            else{
                stock[ctr][ctr2] = beta_arr[beta_ctr];
                beta_ctr++;
            }
        }
    }
}

//A function to print a single dimensional array.
void printArray(int array[],int size){
    for(int ctr=0;ctr<size;ctr++){
        cout<<array[ctr]<<" ";
        if(ctr%14==0 && ctr!=0){
            cout<<endl;
        }
    }
}

//A function that initializes the first column of the
//two dimensional array, inStock, and set the next element of
//the next column to two times the previous column minus the
//corresponding element in the array deltap[].
void setInStock(int stock[][4],int delta_arr[]){
    for(int ctr=0;ctr<10;ctr++){
        cout<<"Column ["<<ctr<<"][0]: ";
        cin>>stock[ctr][0];
    }
    for(int ctr=1;ctr<4;ctr++){
        for(int ctr2=0;ctr2<10;ctr2++){
            stock[ctr2][ctr] = 2*stock[ctr2][ctr-1]-delta_arr[ctr2];
        }
    }
}

//A function to print a two dimensional array.
void printTwoDimensional(int stock[][4]){
    for(int ctr=0;ctr<10;ctr++){
        for(int ctr2=0;ctr2<4;ctr2++){
            cout<<stock[ctr][ctr2]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int inStock[10][4];
    int alpha[20];
    int beta[20];
    int gamma[4] = {11,13,15,17};
    int delta[10] = {3,5,2,6,10,9,7,11,1,8};
    setZero(gamma,4);
    cout<<"Printing Array Gamma: "<<endl;
    printArray(gamma,4);
    cout<<endl;
    cout<<"Inputting data to Alpha:"<<endl;
    inputArray(alpha);
    cout<<endl;
    cout<<"Printing Alpha: "<<endl;
    printArray(alpha,20);
    cout<<endl;
    cout<<"Doubling Beta: "<<endl;
    doubleArray(beta,alpha);
    cout<<endl;
    cout<<"Printing Beta: ";
    printArray(beta,20);
    cout<<endl;
    gamma[0] = 11;gamma[1] = 13;
    gamma[2] = 15;gamma[3] = 17; 
    cout<<"Doing Copy Gamma: "<<endl;
    copyGamma(gamma,inStock);
    cout<<endl;
    cout<<"Printing inStock: "<<endl;
    printTwoDimensional(inStock);
    cout<<"Doing Copy Alpha-Beta: "<<endl;
    copyAlphaBeta(alpha,beta,inStock);
    cout<<endl;
    cout<<"Printing inStock: "<<endl;
    printTwoDimensional(inStock);
    cout<<endl;
    cout<<"Doing setInStock: "<<endl;
    setInStock(inStock,delta);
    cout<<endl;
    cout<<"Printing inStock: "<<endl;
    printTwoDimensional(inStock);

}