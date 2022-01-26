#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;

void CamelCase(string str)
{ 
    int i = 0;
    while(i<str.length())
    {
        if(isupper(str[i]))
        {
            cout<<str[i];
            i++;
            while(islower(str[i]))
            {
                cout<<str[i];
                i++;
            }
            cout<<endl;
        }
    }
    
}

int main()
{
    string str;
    cin>>str;
    CamelCase(str);
    return 0;
}
