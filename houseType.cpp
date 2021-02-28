#include<iostream>

using namespace std;

//Declare a class with name house type, includes the function prototypes and
//properties within the class. Used outside class definition. Functions with
//'set' changes the value of the specified property. Functions with 'get'
//returns the value of the property.
class houseType{
    public:
        void set(string, int, int, int, int, int, double, double);
        void print() const;
        void setStyle(string);
        string getStyle() const;
        void setNumOfBedrooms(int);
        int getNumOfBedrooms() const;
        void setNumOfBathrooms(int);
        int getNumOfBathrooms() const;
        void setNumOfCarsGarage(int);
        int getNumOfCarsGarage() const;
        void setYearBuilt(int);
        int getYearBuilt() const;
        void setFinishedSquareFootage(int);
        int getFinishedSquareFootage() const;
        void setPrice(double);
        double getPrice() const;
        void setTax(double);
        double getTax() const;
        houseType(string = "", int = 0, int = 0, int = 0, int = 0,
        int = 0, double = 0, double = 0);
    private:
        string style;
        int numOfBedrooms;
        int numOfBathrooms;
        int numOfCarsGarage;
        int yearBuilt;
        int finishedSquareFootage;
        double price;
        double tax;
    };

//Declares an object of type houseType and initializes
//its properties respectively according to Exercise 11.
int main(){
    houseType newHouse();
    houseType house;
    house.setStyle("Ranch");
    house.setNumOfBedrooms(3);
    house.setNumOfBathrooms(2);
    house.setNumOfCarsGarage(2);
    house.setYearBuilt(2005);
    house.setFinishedSquareFootage(1300);
    house.setPrice(185000);
    house.setTax(3600.0);
    house.print();
    
}

//Constructor function that initializes the properties upon declaration.
houseType::houseType(string style, int bedrooms, int bathrooms, int cars, int year,
        int square, double  uprice, double  utax){
            style = style;
            numOfCarsGarage = cars;
            numOfBathrooms = bathrooms;
            numOfBedrooms = bedrooms;
            yearBuilt = year;
            finishedSquareFootage = square;
            price = uprice;
            tax = utax;
}
//Set the properties of the class from the arguments passed.
void houseType::set(string style, int bedrooms,int bathrooms, int carsgarage, int yearbuilt, int sqfootage, double price, double tax){
    this->style = style;
    this->numOfBathrooms = bathrooms;
    this->numOfBedrooms = bedrooms;
    this->numOfCarsGarage = carsgarage;
    this->yearBuilt = yearbuilt;
    this->finishedSquareFootage = sqfootage;
    this->price = price;
    this->tax = tax;
}

//Prints the properties of the object with class houseType.
void houseType::print() const{
    cout<<"House style: "+this->style<<endl;
    cout<<"Number of bedrooms: "<<this->numOfBedrooms<<endl;
    cout<<"Number of bathrooms: "<<this->numOfBathrooms<<endl;
    cout<<"Number of car garages: "<<this->numOfCarsGarage<<endl;
    cout<<"Year built: "<<this->yearBuilt<<endl;
    cout<<"Finished Square Footage: "<<this->finishedSquareFootage<<endl;
    cout<<"Price: "<<this->price<<endl;
    cout<<"Tax: "<<this->tax<<endl;
 }

//Functions with 'set' changes the value of the property specificied
//of the object with the argument passed to the function. While functions
//with 'get' returns the value of the property of the object.
void houseType::setStyle(string style){
     this->style = style;
 }
string houseType::getStyle() const{
     return this->style;
 }

void houseType::setNumOfBathrooms(int bathrooms){
    this->numOfBathrooms = bathrooms;
}
int houseType::getNumOfBathrooms() const{
    return this->numOfBathrooms;
}

void houseType::setNumOfBedrooms(int bedrooms){
    this->numOfBedrooms = bedrooms;
}

int houseType::getNumOfBedrooms() const{
    return this->numOfBedrooms;
}
//Continuation of the function definitions, as stated above. Follows the
//definition for 'set' functions and 'get' functions.
void houseType::setNumOfCarsGarage(int cars){
    this->numOfCarsGarage = cars;
}
int houseType::getNumOfCarsGarage() const{
    return this->numOfCarsGarage;
}
void houseType::setYearBuilt(int year){
    this->yearBuilt = year;
}
int houseType::getYearBuilt() const{
    return this->yearBuilt;
}
void houseType::setFinishedSquareFootage(int squarefootage){
    this->finishedSquareFootage = squarefootage;
}
int houseType::getFinishedSquareFootage() const{
    return this->finishedSquareFootage;
}
void houseType::setPrice(double price){
    this->price = price;
}
double houseType::getPrice() const{
    return this->price;
}
void houseType::setTax(double tax){
    this->tax= tax;
}
double houseType::getTax() const{
    return this->tax;
}