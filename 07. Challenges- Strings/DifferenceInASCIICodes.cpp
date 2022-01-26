#include<iostream>
#include<string>
using namespace std;

void DiffinAsciiCodes(string str)
{

    int i = 0;
    for(;i<str.length()-1;i++)
    {
        cout<<str[i]<<str[i+1]-str[i];  
    }
    cout<<str[i];
}



int main()
{
    string s;
    getline(cin, s);
    DiffinAsciiCodes(s);

    return 0;
}
