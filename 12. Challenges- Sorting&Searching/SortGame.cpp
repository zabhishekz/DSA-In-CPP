#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool compare(pair <string, int> e1, pair <string, int> e2)
{
    if(e1.second == e2.second)
    {
        return e1.first < e2.first;
    }
    return e1.second > e2.second; 

int main()
{
    int x;
    cin>>x;
    int n;
    cin>>n;
    cin.get();

    pair <string, int> employee[100];
    for(int i = 0; i < n; i++)
    {
        cin>>employee[i].first;
        cin>>employee[i].second;
    }

    sort(employee, employee+n, compare);

    for(int i = 0; i < n; i++)
    {
        if(employee[i].second >= x)
            cout<<employee[i].first<<" "<<employee[i].second<<endl;
    }

    return 0;
}