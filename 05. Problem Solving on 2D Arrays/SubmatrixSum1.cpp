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
            cin>>a[i][j];
    }

    for(int li = 0; li < m; li++){
        for(int lj = 0; lj < n; lj++){
            for(int bi = li; bi < m; bi++){
                for(int bj = lj; bj < n; bj++){
                    for(int i = li; i <= bi; i++){
                        for(int j = lj; j <= bj ; j++){
                            sum +=  a[i][j];
                        }       
                    }
                }
            }
        }
    }

    cout<<"Sum of all Submatrices = "<<sum<<endl;
    return 0;
}