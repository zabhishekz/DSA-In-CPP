#include<iostream>
using namespace std;

void stringcompression(string str)
{
    int  i = 0;
    int count;
    while(i < str.length())
    {
        count  = 1;
        cout<<str[i];
        while(str[i] == str[i+1])
        {
            count++;
            i++;
        }
        cout<<count;   
        i++;
    }
}

int main()
{
    string str;
    getline(cin, str);
    stringcompression(str);
    
    return 0;
}