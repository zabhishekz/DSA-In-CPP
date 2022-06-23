#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int maxfreqnum = 0;
    int maxfreq = 0;
    unordered_map<int, int> hm;
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
        hm[arr[i]]++;
    }
    for(auto p : hm){
        if(hm[p.first] > maxfreq){
            maxfreq = hm[p.first];
            maxfreqnum = p.first;
        }
    }
    cout<<maxfreqnum;
    return 0;
}