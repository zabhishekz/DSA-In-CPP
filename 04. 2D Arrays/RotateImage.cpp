#include<iostream>
using namespace std;

void display(int a[][100], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void rotate(int a[][100], int n)
{
    for(int row = 0; row < n; row++)
    {
        int startcol = 0;
        int endcol = n-1;
        while(startcol < endcol)
        {
            swap(a[row][startcol], a[row][endcol]);
            startcol++;
            endcol--;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i < j)
            {
                swap(a[i][j], a[j][i]);
            }
        }
    }

}


int main()
{
    int a[100][100];
    int n;
    cout<<"Enter number of rows and columns: ";
    cin>>n;
    cout<<"Enter elements: "<<endl;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>a[i][j];
        }
    }
    rotate(a,n);
    display(a,n);
    return 0;
}