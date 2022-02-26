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

    car(){
        name = NULL; 
    }
    car(float p, int m, char *n){
        price = p;
        model_no = m;
        name = new char[strlen(n)+1];
        strcpy(name, n);
    }
    car(car &x){
        cout<<"Inside Copy Constructor";
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

    void print(){
        cout<<"Name: "<<name<<endl;
        cout<<"Model Number: "<<model_no<<endl;
        cout<<"Price: "<<price<<endl;
    }
};

int main()
{
    car c(100, 200, "BMW");//para constructor
    car d;//default  constructor
    d = c; //the default copy assignment operator - makes a shallow copy
    //So we override the default copy assignment operator to create a deep copy
    d.set_price(400);
    d.name[0] = 'A';
    c.print();
    d.print();
    return 0;
}