#include<iostream>
#include<vector>
using namespace std;

class stack{
    vector <int> v;
    public:
    void push(int d){
        v.push_back(d); 
    }
    bool empty(){
        return v.size() == 0;
    }
    void pop(){
        if(!empty()){
            v.pop_back();
        }
    }
    int top(){
        return v[v.size()-1];
    }
};

int main()
{
    stack s;
    for(int i = 1; i <= 5; i++){
        s.push(i*i);
    }
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}
