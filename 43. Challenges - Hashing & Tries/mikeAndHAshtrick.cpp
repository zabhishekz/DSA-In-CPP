#include<iostream>
#include<climits>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

unordered_map<int,int>m;
bool mycompare(int a , int b){ 
    //cout << "Comparing " << a << " and " << b << endl;
    return m[a] < m[b];
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for( int i = 0 ; i  < n ;i++){
        cin >> a[i];
    }
    vector<int>ans;
    int val = 0;
    for( int i = 0 ; i  < n ; i++){
        if( m.count(a[i]) ) {
            m[a[i]] = ++val;
        }
        else{
            m[a[i]] = ++val;
            ans.push_back(a[i]); // inserting the unique element into the vector
        }
    }
    sort(ans.begin() , ans.end() , mycompare );
    for( int i = 0  ;  i  < ans.size() ; i++){
        cout << ans[i] << endl;
    }
    return 0;
}