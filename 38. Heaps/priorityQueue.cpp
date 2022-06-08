#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main(){
    priority_queue<int> pq;//part of queue header file
    //maxHeap by default
    //insertion
    int n; 
    cin>>n;
    for(int i = 0; i <n; i++){
        int no;
        cin>>no;
        pq.push(no);
    }

    //Remove
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }

    return 0;
}