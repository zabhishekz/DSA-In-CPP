#include<iostream>
#include<vector>
using namespace std;

bool dfs_helper(vector<int> graph[], int node, int *visited, int parent, int color){
    //come to node 
    visited[node] = color;
    for(auto nbr : graph[node]){
        if(visited[nbr] == 0){
            int subprob = dfs_helper(graph, nbr, visited, node, 3-color);
            if(subprob == false){
                return false;
            }
        }
        else if(nbr != parent and color == visited[nbr]){
            return false;
        }
    } 
    return true;
}

bool dfs(vector<int> graph[], int N){
    int visited[N] = {0};//0-not visited, 1-visited and color is 1, 2-visited and color is 2
    int color = 1;
    int ans = dfs_helper(graph, 0, visited, -1, color);
    //print colors
    for(int i = 0; i < N; i++){
        cout<<i<<" - color "<<visited[i]<<endl;
    }
    return ans;
}

int main(){
    int N, M;
    cin>>N>>M;

    vector<int> graph[N];
    while(M--){
        int x, y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    //BFS or DFS, by coloring node at each step(current node)
    if(dfs(graph, N)){
        cout<<"Yes bipartite";
    }
    else{
        cout<<"Not bipartite";
    }
    return 0;
}