#include<iostream>
#include<set>
#include<climits>
using namespace std;

//Set-elements stored are ordered and unique
int main(){

    set<pair<int,int>> s;
    s.insert(make_pair(10,1));
    s.insert(make_pair(10,5));
    s.insert(make_pair(20,1));
    s.insert(make_pair(20,100));
    s.insert(make_pair(5,1));
    s.insert(make_pair(5,3));
    s.insert(make_pair(5,2));

    //Erasing an element
    s.erase(s.find(make_pair(5,3)));
    s.insert(make_pair(5,4));

    //for-each loop
    for(auto p : s){
        cout<<p.first<<" and "<<p.second<<endl;
    }

    auto it = s.lower_bound(make_pair(20, 1));//>=
    cout<<it->first<<", "<<it->second<<endl;
    auto it2 = s.upper_bound(make_pair(20, 1));//>
    cout<<it2->first<<", "<<it2->second<<endl;

    //Find a pair where x value is atleast >10
    auto it3 = s.lower_bound(make_pair(20, INT_MAX));
    cout<<it3->first<<", "<<it3->second;
    return 0;
}