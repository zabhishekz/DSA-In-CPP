#include<iostream>
using namespace std;

class car{
    float price; //now price is private
public:
    int model_no;
    char name[20];

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
    car c;
    c.model_no = 112;
    c.name[0] = 'B';
    c.name[1] = 'M';
    c.name[2] = 'W';
    c.name[3] = '\0';

    c.set_price(-100);
    c.print();
    return 0;
}