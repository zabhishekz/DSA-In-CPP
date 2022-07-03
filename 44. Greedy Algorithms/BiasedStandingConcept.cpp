#include <iostream>
#include <cstring>
using namespace std;

int abst(int i , int j){
    if(i-j > 0){
        return i-j;
    }
    else{
        return j-i;
    }
}

int main(){
    int arr[100000] = {0};
    int t, n;
    cin>>t;

    while(t--){
        memset(arr, 0, sizeof(arr));
        string name;
        int n, rank;
        cin>>n;
        for(int i = 1; i< n; i++){
            cin>>name;
            cin>>rank;
            arr[rank]++;
        }
        //Greedy approach- assign the team the nearest rank available
        int actual_rank = 1;
        int sum = 0;
        for(int i = 1; i <= n; i++){
            while(arr[i]){
                sum += abst(actual_rank, i);
                arr[i]--;
                actual_rank++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}