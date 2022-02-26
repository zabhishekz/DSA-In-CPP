/*special functions that C++ classes give you when you create a class/object.
4 different special fns that are always present inside a class.
1.Constructor
    - that is responsible for creating an object
    - gets called automatically and only once.
    - same name as class name
    - Constructor has some parameters- parameterized constructors
    - multiple constructors in same class - constructor overloading
2.Copy constructor
    - make a copy of the given object
    - exists by default
*/
#include<iostream>
#include<cstring>
using namespace std;

class car{
    float price;
public:
    int model_no;
    char name[20];

    //Constructors
    //default constructor
    car(){
        cout<<"Inside default constructor of class car";
    }

    //parameterized constructor
    car(float p, int m, char *n){
        cout<<"Inside parameterized constructor of class car";
        price = p;
        model_no = m;
        strcpy(name, n);
    }

    car(float p){
        price = p;
    }

    //There is no need to create a copy constructor as it is present by default, here it
    //is only what's inside it, and we are overriding it
    /*"a copy constructor must pass its first argument by reference"- Why?

    */
    car(car &x){
        cout<<"Inside copy constructor of class car";
        price = x.price;
        model_no = x.model_no;
        strcpy(name, x.name);
    }

    void print(){
        cout<<"Name: "<<name<<endl;
        cout<<"Model Number: "<<model_no<<endl;
        cout<<"Price: "<<price<<endl;
    }

    float apply_discount(float x){
        price = price*(1.0 - x);
        return price;
    }

    void set_price(float p){//fucnction used to access(write) the private value- setters
        float msp = 111;
        if(p > msp){
            price = p;
        }
        else{
            price = msp;
        }
    }

    float get_price(){//fucnction used to access(read) the private value - getters
        return price;
    }
};

int main()
{
    car c;//default constructor is called
    c.model_no = 112;
    c.name[0] = 'B';
    c.name[1] = 'M';
    c.name[2] = 'W';
    c.name[3] = '\0';
    c.set_price(-100);
    cout<<endl<<"Car c: "<<endl;
    c.print();
    cout<<endl;
    
    car d(222, 333, "Audi");//parameterised constructor is called
    cout<<endl<<"Car d: "<<endl;
    d.print();
    cout<<endl;

    car e(d);//copy constructor is called(which is inside class by default)
    e.set_price(456);//update price of e
    cout<<endl<<"Car e: "<<endl;
    e.print();
    cout<<endl;

    //another way to call a copy constructor
    car f = e;
    cout<<endl<<"Car f: "<<endl;
    f.print();
    return 0;
}