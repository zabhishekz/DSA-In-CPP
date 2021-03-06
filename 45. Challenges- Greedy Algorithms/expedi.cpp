#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

bool compare(pair<long long, long long> p1, pair<long long, long long> p2){
    return p1.first > p2.first;
}

int main(){
    long long n, t, x, d, f, D, F, prev = 0;
    long long flag = 0;
    long long ans = 0;
    vector<pair<long long, long long>> v;
    priority_queue<long long> pq;
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>d>>f;
        v.push_back(make_pair(d, f));
    }
    sort(v.begin(), v.end(), compare);
    cin>>D>>F;
    for(int i = 0; i < n; i++){
        v[i].first = D-v[i].first;
    }
    prev = 0;//denotes the previous city we have visited
    x = 0;//current city
    while(x < n){
        //if we have enough fuel to go to next city
        if(F >= (v[x].first-prev)){
            F = F-(v[x].first-prev);
            pq.push(v[x].second);
            prev=v[x].first;
        }
        else{
            //check if you have some fueling stations visited in the priority queue
            if(pq.empty()){
                flag = 1;
                break;
            }
            //otherwise refuel the truck with fuel stations with higher capacity
            F += pq.top();
            //Remove the fuel station from priority queue
            pq.pop();
            ans += 1;
            continue;
        }
        x++;
    }
    //actually travelled through n fuel stations
    //what is left you have reach the town from the last fuel station
    if(flag == 1){
        cout<<-1<<endl;
    } 
    //otherwise
    D = D - v[n-1].first;
    if(F >= D){
        cout<<ans;
    }
    //otherwise
    while(F < D){
        if(pq.empty()){
            flag = 1;
            break;
        }
        F += pq.top();
        pq.pop();
        ans += 1;
    }
    return 0;   
}