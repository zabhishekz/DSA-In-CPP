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
    - default copy constructor makes a copy that is called shallow copy.
    - When do we need to define your own copy constructor?
    - You have to mke your own copy constructor if a deep copy is needed
3. Copy Assignment operator =
    - copies object when you do assignment
    - car d = c // copy constructor is called
    - car d
      d = c // copy assignment operator
    - you can write your own copy assignment operator to make a deep copy
    - can be caleed many times unlike the constructor
4. destructor
    - Clear out the memory occupied by the object
    - automatically when the object goes out of scope
    - except for the cases when you have dynamically allocated members in the class
    
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

    ~car(){
        cout<<"Inside destructor of class car "<<name<<endl;
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