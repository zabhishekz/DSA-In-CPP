#include<iostream>
#include<list>
using namespace std;

int main(){
    list <int> l;
    list <int> l1{1, 2, 3, 10, 5, 8};
    list <string> l2{"apple", "guava", "mango", "banana"};
    l2.push_back("pinneapple");

    //iterate and print
    for(string s: l2){
        cout<<s<<"-->";
    }
    cout<<endl;

    //sort -lexicographically
    l2.sort();
    for(string s: l2){
        cout<<s<<"-->";
    }
    cout<<endl;

    //reverse
    l2.reverse();
    for(string s: l2){
        cout<<s<<"-->";
    }
    cout<<endl;

    //remove at beginning
    cout<<l2.front()<<endl;
    l2.pop_front();
    for(string s: l2){
        cout<<s<<"-->";
    }
    cout<<endl;

    //insert at beginning
    l2.push_front("kiwi");
    //remove at end
    cout<<l2.back()<<endl;
    l2.pop_back();

    for(string s: l2){
        cout<<s<<"-->";
    }
    cout<<endl;

    //iterate over the list
    for(auto it = l2.begin(); it != l2.end(); it++){
        cout<<*it<<" -> ";
    }
    cout<<endl;


    //some more functions
    l2.push_back("orange");
    l2.push_back("guava");
    for(auto s: l2){
        cout<<s<<"-->";
    }
    cout<<endl;

    //remove an element by value
    string f;
    cin>>f;
    l2.remove(f);//remove all occurrences of fruit f
    for(auto s: l2){
        cout<<s<<"-->";
    }
    cout<<endl;

    //erase one or more element
    auto it = l2.begin();
    it++;
    it++;
    l2.erase(it);
    for(auto s: l2){
        cout<<s<<"-->";
    }
    cout<<endl; 

    it = l2.begin();
    it++;
    l2.insert(it, "FruitJuice");
    for(auto s: l2){
        cout<<s<<"-->";
    }
    cout<<endl; 

    cout<<l2.empty();
    l2.pop_back();
    l2.pop_back();
    l2.pop_back();
    l2.pop_back();
    cout<<l2.empty();
    return 0;
}