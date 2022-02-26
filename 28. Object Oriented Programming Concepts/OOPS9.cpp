/*
Const data members - once initialized and can't be changed
Initialization list - Initialisez constant as well as other non constant data members
constant parameter - which dont get updated in functions they are used
constant functions - which dont update data memebers of class
*/
#include<iostream>
#include<cstring>   
using namespace std;
//shallow copy - by default copy constructor
class car{
    float price;
public:
    int model_no;
    char *name;
    const int msp;

    car():msp(99){
        name = NULL; 
    }
    car(float p, int m, char *n, int minprice=99):price(p),msp(minprice){
        model_no = m;
        name = new char[strlen(n)+1];
        strcpy(name, n);
    }
    car(const car &x):msp(x.msp){
        price = x.price;
        model_no = x.model_no;
        name = new char[strlen(x.name) + 1];
        strcpy(name, x.name); 
    }
    void operator=(car &x){
        //our copy assignment operator to create a deep copy
        price = x.price;
        model_no = x.model_no;
        name = new char[strlen(x.name) + 1];
        strcpy(name, x.name); 
    }
    void set_price(float p){
        price = p;
    }

    void print() const{
        cout<<"Name: "<<name<<endl;
        cout<<"Model Number: "<<model_no<<endl;
        cout<<"Price: "<<price<<endl;
    }
    float apply_discount(const float x){
        price = price*(1.0 - x);
        return price;
    }
    float get_price() const  {
        return price;
    }
};

int main()
{
    car c(100, 200, "BMW");//para constructor
    cout<<c.msp<<endl;
    car d;//default  constructor
    d = c; //the default copy assignment operator - makes a shallow copy
    //So we override the default copy assignment operator to create a deep copy
    d.set_price(400);
    d.name[0] = 'A';
    c.print();
    d.print();
    return 0;
}