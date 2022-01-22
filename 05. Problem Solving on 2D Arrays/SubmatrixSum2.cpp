#include <iostream>
using namespace std;
int main()
{
    int m, n, a[100][100];
    cout<<"Enter number of rows: ";
    cin>>m;
    cout<<"Enter number of columns: ";
    cin>>n;

    cout<<"Enter matrix elements: "<<endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin>>a[i][j];
        }
    }
    
    for(int i = 0; i < m; i++){
        for(int j = 1; j < n; j++){
            a[i][j] += a[i][j-1];
        }
    }

    for(int j = 0; j < n; j++){
        for(int i = 1; i < m; i++){
            a[i][j] += a[i-1][j];
        }
    }

    cout<<"Prefix sum matrix: "<<endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    int sum=0;
    for(int li = 0; li < m; li++){
        for(int lj = 0; lj < n; lj++){
            for(int bi = li; bi < m; bi++){
                for(int bj = lj; bj < n ; bj++){
                    sum = sum + a[bi][bj];
                    if(li > 0)
                        sum -= a[li-1][bj];
                    if(lj > 0)
                        sum -= a[bi][lj-1];
                    if(li > 0 && lj > 0)
                        sum += a[li-1][lj-1];
                }
            }
        }
    }

    cout<<"Sum of all Submatrices = "<<sum<<endl;

    return 0;
}