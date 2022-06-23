#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    int no;
    int arr[n];
    unordered_map<int, int> hm;

    for(int i = 0; i < n; i++){
        cin>>no;
        arr[i] = no;
        hm[no] = i;     
    }

    for(int i = n; i >= 1; i--){
        if(k <= 0){
            break;
        }
        int num = i;
        int ini_idx = hm[num];
        int best_idx = n-num;
        if(ini_idx == best_idx){
            continue;
        }
        int temp = arr[best_idx]; 
        hm[num] = best_idx;
        hm[temp] = ini_idx;
        swap(arr[ini_idx], arr[best_idx]);
        k--;
    }

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}