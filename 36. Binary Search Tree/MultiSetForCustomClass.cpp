#include<iostream>
#include<set>
using namespace std;

class person_compare{
    public:
    bool operator()(pair<string, int> p1, pair<string, int> p2){
        return p1.second < p2.second;
    }
};

int main(){
    pair<string, int> p1 = make_pair("B",100);
    pair<string, int> p2 = make_pair("A",40);
    pair<string, int> p3 = make_pair("C",120);
    pair<string, int> p4 = make_pair("D",10);
    //Multiset 
    //custom data type
    multiset<pair<string, int>> m;
    m.insert(p1);
    m.insert(p2);
    m.insert(p3);
    m.insert(p4);
    //pairs ordered lexicographically according to first element
    for(auto p : m){
        cout<<p.first<<" and "<<p.second<<endl;
    }


    cout<<endl<<endl<<endl;
    //Now using custom user defined class
    multiset<pair<string, int>, person_compare> m1;
    m1.insert(p1);
    m1.insert(p2);
    m1.insert(p3);
    m1.insert(p4);
    for(auto p : m1){
        cout<<p.first<<" and "<<p.second<<endl;
    }

    return 0;
}