#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    int x[100000], y[100000];
    int dx = 0;
    int dy = 0;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>x[i]>>y[i];
    }
    sort(x, x+n);
    sort(y, y+n);
    for(int i = 1; i < n; i++){
        dx = max(dx, x[i]-x[i-1]-1);
        dy = max(dy, y[i]-y[i-1]-1);
    }
    cout<<dx*dy<<endl;
    return 0;
}