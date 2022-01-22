#include<iostream>
using namespace std;

int main()
{
    int a[100][100];
    int m, n;
    cout<<"Enter number of rows: ";
    cin>>m;
    cout<<"Enter number of columns: ";
    cin>>n;

    int val = 1;
    
    for(int i = 0; i < m; i++)
    {    for(int j = 0; j < n; j++)
        {
            a[i][j] = val;
            val += 1;
        }
    }
    
    for(int j = 0; j < n; j++)
    {   if(j%2 == 0)
        {   for(int i = 0; i < m; i++)
            {
                cout<<a[i][j]<<" ";
            }
        }
        else
        {   for(int i = m-1; i>=0; i--)
            {
                cout<<a[i][j]<<" ";
            }
        }
    }
    return 0;
}