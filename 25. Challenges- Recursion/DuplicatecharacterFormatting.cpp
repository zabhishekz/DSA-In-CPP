#include<iostream>
using namespace std;

void DuplicateCharacterFormatting(char a[], int i)
{
    if(a[i] == '\0' or a[i+1] == '\0')
    {
        return;
    }
    if(a[i] == a[i+1])
    {
        int j = i+1;
        while(a[j] != '\0')
        {
            j++;
        }
        while(j >= i+1)
        {
            a[j+1] = a[j];
            j--;
        }
        a[i+1]='*';
        DuplicateCharacterFormatting(a, i+2);
    }
    else
    {
        DuplicateCharacterFormatting(a,i+1);
    }
    return;
}

int main()
{
    char a[10000];
    cin>>a;
    DuplicateCharacterFormatting(a, 0);
    cout<<a;
    return 0;
} 