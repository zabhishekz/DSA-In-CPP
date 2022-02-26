#include<iostream>
using namespace std;

class car{
public:
    float price;
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
};

int main()
{
    car c;
    c.price = 100;
    c.model_no = 112;
    c.name[0] = 'B';
    c.name[1] = 'M';
    c.name[2] = 'W';
    c.name[3] = '\0';

    float disc;
    cout<<"Enter discount you want to give: ";
    cin>>disc;
    cout<<c.apply_discount(disc)<<endl;
    c.print();
    return 0;
}