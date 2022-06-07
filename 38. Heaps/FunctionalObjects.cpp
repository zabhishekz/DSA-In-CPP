#include<iostream>
#include<cstring>
using namespace std;

class Fun{
    public:
    void operator()(string s){
        cout<<"having Fun with "<<s;
    }
};

int main(){
    Fun f;//constructor
    f("C++");//overload () operator = function call where f is an object
    return 0;
}