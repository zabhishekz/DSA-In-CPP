#include<iostream>
using namespace std;

void RemoveDuplicates(char a[])
{
    if(a[0] == '\0')
    {
        return;
    }
    if(a[0] == a[1])
    {
        int i = 0;
        while(a[i]!='\0')
        {
            a[i]=a[i+1];
            i++;
        }
        RemoveDuplicates(a);
    }
    else
    {
        RemoveDuplicates(a+1);
    }
    return;
}

int main()
{
    char a[10000];
    cin>>a;
    RemoveDuplicates(a);
    cout<<a;
    return 0;
} 