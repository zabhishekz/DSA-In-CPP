#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

class car
{
    public:
    string car_name;
    int x, y;
    car() {}
    car(string n, int x, int y)
    {
        car_name = n;
        this->x = x;
        this->y = y;
    }
    int dist()
    {
        //returns square of distance from origin of a car 
        return x*x + y*y;
    }
};

bool compare(car a, car b)
{
    int d1 = a.dist();
    int d2 = b.dist();
    if(d1==d2)
    {
        return a.car_name< b.car_name;
    }
    return d1< d2;
}

int main()
{   
    int n;
    cin>>n;
    vector < car> v;
    for(int i = 0; i< n; i++)
    {
        int x, y;
        string name;
        cin>>name>>x>>y;
        car temp(name, x, y);
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), compare);
    for( auto c: v)
    {
        cout<<"Car "<<c.car_name<<", Distance "<<c.dist()<<", Location "<<c.x<<", "<<c.y<<endl;
    }
    
    return 0;
}