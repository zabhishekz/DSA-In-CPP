#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector <int> d = {1, 2, 3, 10, 14};
    //PushBack
    d.push_back(16);
    for(int x: d)
    {
        cout<<x<<", ";
    }
    cout<<endl;

    //PopBack
    d.pop_back();
    for(int x: d)
    {
        cout<<x<<", ";
    }
    cout<<endl;

    //Inserting elements
    d.insert(d.begin()+3, 100);
    for(int x: d)
    {
        cout<<x<<", ";
    }

    cout<<endl;
    d.insert(d.begin()+3,4, 100);
    for(int x: d)
    {
        cout<<x<<", ";
    }

    //Removing elements
    cout<<endl;
    d.erase(d.begin()+3);
    for(int x: d)
    {
        cout<<x<<", ";
    }

    cout<<endl;
    d.erase(d.begin()+2);
    for(int x: d)
    {
        cout<<x<<", ";
    }

    cout<<endl;
    d.erase(d.begin()+2, d.begin()+5);
    for(int x: d)
    {
        cout<<x<<", ";
    }

    cout<<endl;
    cout<<"Size: "<<d.size()<<endl;
    cout<<"Capacity: "<<d.capacity()<<endl;

    //Resize
    d.resize(8);
    cout<<"Capacity: "<<d.capacity()<<endl;

    d.resize(18);
    cout<<"Capacity: "<<d.capacity()<<endl;

    d.clear();
    cout<<"Size: "<<d.size()<<endl;
    cout<<"Capacity: "<<d.capacity()<<endl;

    if(d.empty())
        cout<<"Empty Vector"<<endl;

    d.push_back(10);
    d.push_back(11);
    d.push_back(12);
    cout<<d.front()<<endl;
    cout<<d.back()<<endl;

    //Normal approach
    int n;
    cin>>n;
    vector <int> v;
    for( int i = 0; i<n; i++)
    {
        int no;
        cin>>no;
        v.push_back(no);
        cout<<"Changing Capacity "<<v.capacity()<<endl;
    }
    cout<<"Capacity "<<v.capacity()<<endl;
    for(int x: v)
    {
        cout<<x<<", ";
    }
    cout<<endl;

    //Reserve
    cin>>n;
    vector <int> w;
    w.reserve(1000);
    for( int i = 0; i<n; i++)
    {
        int no;
        cin>>no;
        w.push_back(no);
        cout<<"Changing Capacity "<<w.capacity()<<endl;
    }
    cout<<"Capacity "<<w.capacity()<<endl;
    for(int x: w)
    {
        cout<<x<<", ";
    }


    return 0;
}