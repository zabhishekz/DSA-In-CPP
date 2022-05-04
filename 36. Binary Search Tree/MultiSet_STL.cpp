#include<iostream>
#include<set>
using namespace std;

//Multiset-can store multiple elements that have same values
//all elemts are stored in a specific order->stored according to the internal comparison object
//values once inserted can't be modified
//Associative container- elements are referred by key/value, not index
//underlying implementation is a BST


typedef multiset<int>::iterator It;

int main(){
    int arr[] = {10, 20 ,30, 20, 10, 30, 30, 30, 10, 30};
    int n = sizeof(arr)/sizeof(int);
    multiset<int> m(arr, arr+n);
    
    //Iterate
    for(int x:m){
        cout<<x<<", ";
    }
    cout<<endl;

    //erase 20 - removes all occurrences of 20 from the set
    m.erase(20);
    for(int x:m){
        cout<<x<<", ";
    }
    cout<<endl;

    //insert elements
    m.insert(80);
    for(int x:m){
        cout<<x<<", ";
    }
    cout<<endl;

    //count occurences of an element
    cout<<"Count "<<m.count(10)<<endl;

    //finds first occurrence of element
    auto it = m.find(30);
    cout<<*(it)<<endl;

    //find all occurrences of an element
    pair<It, It> range = m.equal_range(30);
    
    for(auto it = range.first; it!=range.second; it++){
        cout<<*(it)<<" - ";
    }
    cout<<endl;

    //Lower bound >= and upper bound >
    for(auto it = m.lower_bound(10); it != m.upper_bound(77); it++){
        cout<<*(it)<<" - ";
    }
    cout<<endl;
    return 0;
}