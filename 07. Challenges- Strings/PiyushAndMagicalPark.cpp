#include<iostream>
using namespace std;

void magicalpark(char a[][100], int n, int m, int k, int s)
{
    bool success = true;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            char ch = a[i][j];
            if(s < k)
            {
                success = false;
                break;
            }
            if(ch == '*')
                s += 5;
            if(ch == '.')
                s -= 2;
            if( ch=='#')
                break;
            if(j != m-1)
                s--;
        }
    }

    if(success)
        cout<<"Yes"<<endl<<s;
    else
    {
        cout<<"No";
    }
    

}

int main()
{
    int m, n, k, s;
    cin>>n>>m>>k>>s;
    char park[100][100];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>park[i][j];
        }
    }
    magicalpark(park, n, m, k, s);
    return 0;
}