//Genralization through template class
#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class stack{
    vector <T> v;
    public:
    void push(T d){
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
    T top(){
        return v[v.size()-1];
    }
};

int main()
{
    stack<int> s;
    for(int i = 1; i <= 5; i++){
        s.push(i*i);
    }
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    stack<char> s2;
    for(int i = 65; i <= 70; i++){
        s2.push(i);
    }
    while(!s2.empty()){
        cout<<s2.top()<<endl;
        s2.pop();
    }

    

    return 0;
}
