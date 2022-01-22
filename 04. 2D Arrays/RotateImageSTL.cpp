#include<iostream>
#include<algorithm>
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

void rotate_stl(int a[][100], int n)
{
    for(int i = 0; i < n; i++)
    {
      reverse(a[i], a[i]+n);
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
    rotate_stl(a,n);
    display(a,n);
    return 0;
}