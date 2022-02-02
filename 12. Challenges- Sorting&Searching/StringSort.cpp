#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool compare(string s1, string s2)
{
    // cout<<"comparing "<<s1<<" and "<<s2<<endl;
    int i = 0;      
    while (i < s1.length() && i < s2.length())
    {
        if (s1[i] < s2[i])
        {
            return true;
        }
        else if (s1[i] > s2[i])
        {
            return false;
        }
        i++;
    }
    return (s1.length() > s2.length());
}


int main()
{
    int n;
    cin>>n;
    cin.get();

    string s[1000];
    for(int i=0;i<n;i++)
    {
        getline(cin,s[i]);
    }
    sort(s,s+n,compare);
    for(int i=0;i<n;i++)
    {
        cout<<s[i]<<endl;
    }
    return 0;
}