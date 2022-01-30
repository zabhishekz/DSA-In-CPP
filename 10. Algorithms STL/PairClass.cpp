#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    pair <int, char> p;
    p.first = 10;
    p.second = 'B';
    
    pair <int, char> p2(p);
    cout<<p2.first<<endl;
    cout<<p2.second<<endl;

    pair <int, string> p3 = make_pair(100, "Audi");
    cout<<p3.first<<" "<<p3.second<<endl;

    int a, b;
    cin>>a>>b;
    pair <int, int> p4 = make_pair(a, b);
    cout<<p4.first<<endl;
    cout<<p4.second<<endl;

    pair <pair<int, int>, string> car;
    car.second = "Audi";
    car.first.first = 10;
    car.first.second = 20;
    cout<<car.first.first<<endl;
    cout<<car.second;
    return 0;    

}