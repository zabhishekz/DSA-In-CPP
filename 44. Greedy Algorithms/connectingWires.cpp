//connecting wires
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(){
    priority_queue<int> pq;
    int arr[10];
    for(auto a: arr){   
        pq.push(a);
    }
    int ans = 0;
    while(!pq.empty){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        ans += (a+b);
        pq.push(ans);
    }
    return 0;
}