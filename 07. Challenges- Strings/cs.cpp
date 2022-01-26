#include<iostream>
#include<string>
using namespace std;

void ultrafastmaths(string s1, string s2)
{
    string s3;
    for(int i = 0; i < s1.length(); i++)
    {
        if(s1[i] != s2[i])
        {    
            s3[i]='1';
        }
        else
        {
            s3[i]='0';
        }
    }
    for(int  i = 0; i < s3.length(); i++)
        cout<<s3[i];
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