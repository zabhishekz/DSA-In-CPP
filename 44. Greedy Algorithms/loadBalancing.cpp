#include<iostream>
using namespace std;

int main(){
    int arr[9000];
    int n, val, i, diff;
    while(1){
        //Take input current test case
        int max_load = 0;
        int load = 0;
        cin>>n;
        //stop taking input if n == -1
        if(n == -1){
            break;
        }
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            load += arr[i];
        }
        if(load%n != 0){
            cout<<"-1"<<endl;
        }
        //find the load that is to be divided equally
        load = load/n;

        //greedy step
        diff = 0;
        for(int i = 0; i < n; i++){
            //find the difference between final load to be assigned and current load
            diff += (arr[i]-load);
            int ans = max(diff, -diff);
            max_load = max(max_load, ans);
        }
        cout<<max_load<<endl;
    }
    return 0;
}