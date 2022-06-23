#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;
    unordered_map<int, int> hm;
    unordered_map<int, int> hm2;
    int arr[n], arr2[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        if(hm.count(arr[i]) != 0){
            hm[arr[i]] = hm[arr[i]] + 1;
        }
        else{
            hm[arr[i]] = 1;
        }
    }
    for(int i = 0; i < n; i++){
        cin>>arr2[i];
        if(hm2.count(arr2[i]) != 0){
            hm2[arr2[i]] = hm2[arr2[i]] + 1;
        }
        else{
            hm2[arr2[i]] = 1;
        }
    }

    vector<int> res;
    for(int i = 0; i < n; i++){
        if(hm.count(arr[i]) and hm2.count(arr[i])) {
            if(hm[arr[i]] != 0 and hm2[arr[i]] != 0){
                res.push_back(arr[i]);
                hm[arr[i]] = hm[arr[i]] - 1;
                hm2[arr[i]] = hm2[arr[i]] - 1;
            }
        }
    }
    int m =res.size();
    sort(res.begin(), res.end());
    cout<<"[";
    auto i = res.begin();
    for(; i != prev(res.end()); i++){
        cout<<*i<<", ";
    }
    cout<<*i<<"]";
    return 0;
}