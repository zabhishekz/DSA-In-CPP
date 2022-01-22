#include<iostream>
using namespace std;

int main() 
{
    int m, n, i, j, x;
    cout<<"Enter number of rows: ";
    cin>>m;
    cout<<"Enter number of columns: ";
    cin>>n;
    int a[10][10];
    cout<<"Enter elements: "<<endl;
    for(i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"Enter the no. to be searched :";
    cin>>x;

    i = 0;
    j = n-1;
    int pass = 0;
    while(i < m && j < n)
    {
        if(a[i][j] == x)
        {
            pass = 1;
            break;
        }
        else if(x < a[i][j])
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    if(pass == 1)
    cout<<"No. found at row = "<<i+1<<", column = "<<j+1<<endl;
    return 0;
}