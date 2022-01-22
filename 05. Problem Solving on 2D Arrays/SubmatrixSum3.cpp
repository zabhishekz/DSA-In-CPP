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
    int sum = 0;
    
    cout<<"Enter matrix elements: "<<endl;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>a[i][j];
        }
    }

    for(int i = 0; i < m; i++)
    {   
        for(int j = 0; j < n; j++)
        {
            int tl = (i+1) * (j+1);
            int br = (m-i) * (n-j);
            sum += (tl * br * a[i][j]);
        }
    }
    cout<<"Sum of all Submatrices = "<<sum<<endl;
    return 0;
}