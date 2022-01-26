#include<iostream>
#include<cstring>
using namespace std;

bool isPalindrome(char a[], int l, int r)
{
    if(strlen(a) == 1 or strlen(a) == 0)
        return true;
    if(a[l] == a[r])
        isPalindrome(a, l+1, r-1);
    if(a[l] != a[r])
        return false;
    
    return true;
}

int main()
{
    char a[1000];
    int n;
    cin>>n;
    for(int i =0; i<n ;i++)
        cin>>a[i];

    if(isPalindrome(a, 0, n-1))
        cout<<"true";
    else
    {
        cout<<"false";
    }

    return 0;
}
