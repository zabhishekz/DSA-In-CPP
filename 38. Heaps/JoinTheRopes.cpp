#include<iostream>
#include<queue>
using namespace std;

/*
Problem Statement-Given N ropes of different sizes, we have to join the ropes together
-----------
The cost of joining 2 ropes of different sizes A and B is (A+B). Find the minimum
cost to join all the ropes together.
*/

int join_ropes(int ropes[], int n){
    priority_queue <int, vector<int>, greater<int>> pq(ropes, ropes+n);//initialization
    int cost = 0;
    while(pq.size() > 1){
        int A = pq.top();
        pq.pop();
        int B= pq.top();
        pq.pop();

        int new_rope = (A+B);
        cost += (A+B);

        pq.push(new_rope);
    }
    return cost;
}

int main(){
    int ropes[] ={4, 3, 2, 6};
    int n = 4;
    cout<<"Minimum cost is "<<join_ropes(ropes, n)<<endl; 

    return 0;
}