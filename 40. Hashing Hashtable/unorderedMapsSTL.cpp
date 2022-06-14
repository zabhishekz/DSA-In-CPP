//Unordered Map STL - Hashtable
//All functions in O(1) on average
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main(){
    unordered_map<string, int> m;

    //1.Insert
    m.insert(make_pair("Mango", 100));

    pair<string, int> p;
    p.first = "Apple";
    p.second = 120;
    m.insert(p);

    m["Banana"] = 20;

    //2.Search
    string fruit;
    cin>>fruit;
    auto it = m.find(fruit);//find function returns an iterator
    if(it != m.end()){
        cout<<"Price of "<<fruit<<" is "<<m[fruit]<<endl;
    }
    else{
        cout<<fruit<<" is not present";
    }

    //another way to find a particular map
    //It stores unique keys only once
    if(m.count(fruit)){//count function returns an integer
        cout<<"Price is "<<m[fruit]<<endl;
    }
    else{
        cout<<"Could not find this fruit";
    }

    //3.Erase
    m.erase(fruit);

    //4.Update
    m[fruit] += 22;

    //Iterate over all the key value pairs
    m["Litchi"] = 60;
    m["Pineapple"] = 80;
    for(auto it2 = m.begin(); it2 != m.end(); it2++){
        cout<<it2->first<<" and "<<(*it2).second<<endl;
    }
    //for-each loop
    for(auto p : m){
        cout<<p.first<<" : "<<p.second<<endl;
    }


    return 0;
}