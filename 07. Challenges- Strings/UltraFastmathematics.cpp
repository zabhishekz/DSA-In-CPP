#include<iostream>
#include<string>
using namespace std;

void ultrafastmaths(string str1, string str2)
{
    for(int i = 0; i < str1.length(); i++)
    {
        if(str1[i] != str2[i])
        {    
            cout<<"1";
        }
        else
        {
            cout<<"0";
        }
    }
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        string str1, str2;
        cin>>str1;
        cin>>str2;
        ultrafastmaths(str1, str2);
        t--;
    }
    return 0;
}