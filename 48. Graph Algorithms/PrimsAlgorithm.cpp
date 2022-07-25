#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Graph{
    //Adjacenecy list
    //pointer to an array of vectors
    vector<pair<int, int>> *l;
    int V;
public:
    Graph(int n){
        V = n;
        //array (of size n) of vectors
        l = new vector<pair<int, int>> [n];
    }
    void addEdge(int x, int y, int w){
        l[x].push_back({y, w});
        l[y].push_back({x, w});
    }
    int prim_mst(){
        //Init a minHeap    
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > Q;

        //visited array dentoes whether node is  in MST or not
        bool *vis = new bool[V]{0};
        int ans = 0;

        //begin
        Q.push({0, 0});//weight, node

        while(!Q.empty()){
            //pick up the edge with min weight
            auto best = Q.top();
            Q.pop();

            int to = best.second;
            int weight = best.first;

            if(vis[to]){
                //discared edge and continue 
                continue;
            }

            //otherwise take the current edge
            ans += weight;
            vis[to] = 1;

            //add the new edges into the queue
            for(auto x: l[to]){
                if(vis[x.first] == 0){
                    Q.push({x.second, x.first});
                }
            }
            cout<<ans<<" ";
        }
        return ans;
    }
};

int main(){
    int n, m;
    cin>>n>>m;
    Graph g(n);
    for(int i =0 ; i < m; i++){
        int x, y, w;
        cin>>x>>y>>w;
        g.addEdge(x-1, y-1, w);
    }
    cout<<g.prim_mst()<<endl;

    return 0;
}

