#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n = 7;
    int arr[7]={0};
    
    int x;
    for(int i = 1; i <= n; i++){
        cin>>x;
        arr[x]++;
    }

    int actualrank = 1;
    int sum = 0;

    for(int i = 1; i <= n; i++){
        while(arr[i] > 0){
            sum += abst(actualrank,i);
            actualrank++;
            arr[i]--;
        }
    }
    return 0;
}