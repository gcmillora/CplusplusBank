#include<iostream>

using namespace std;

void selectionSort(int array[], int size) {
    int smallest;
    int temp;
    for(int ctr=0;ctr<size;ctr++){
        smallest=ctr;
        for(int ctr2=ctr+1;ctr2<size;ctr2++){
            if(array[ctr2]<array[smallest])
                smallest = ctr2;
        }
        temp = array[smallest];
        array[smallest] = array[ctr];
        array[ctr] = temp;
        for(int ctr3=0;ctr3<size;ctr3++){
            cout<<array[ctr3]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int array[] = {6,45,10,25,58,2,50,30,86};
    selectionSort(array,9);
}