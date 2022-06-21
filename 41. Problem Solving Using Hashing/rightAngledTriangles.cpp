#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;
    pair<int, int> p[n];
    for(int i = 0; i < n; i++){
        int x, y;
        cin>>x>>y;
        p[i].first = x;
        p[i].second = y;
    }

    unordered_map<int, int> hx;
    unordered_map<int, int> hy;
    for(int i = 0; i < n; i++){
        int x = p[i].first;
        int y = p[i].second;
        hx[x]++;
        hy[y]++;      
    }

    int total = 0;
    for(int i = 0; i < n; i++){
        int x = p[i].first;
        int y = p[i].second;  
        total += (hx[x]-1)*(hy[y]-1);
    }
    
    cout<<"Total number of possible right angled triangles is "<<total;

    return 0;
}