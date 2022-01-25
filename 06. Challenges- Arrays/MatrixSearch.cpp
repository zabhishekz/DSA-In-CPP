#include<iostream>
#include<algorithm>
using namespace std;

int searchmatrix(int a[][100], int n, int m, int x)
{ 
    int i = 0;
    int j = m-1;
    int flag = 0;
    while(i<n and j<m)
    {
        if(a[i][j] == x)
        {
            flag = 1;
            break;
        }
        else if(a[i][j] < x)
        {
            i++;
        }
        else
        {
            j--;
        }
        
    }
    return flag;
}

int main()
{  
    int a[100][100];
    int n, m, x;
    cin>>n>>m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>a[i][j];
    cin>>x;
    
    cout<<searchmatrix(a, n, m, x);

    return 0;
}