#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V]; 
    }
    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void printAdjList(){
        for(int i = 0; i < V; i++){
            for(int nbr: l[i]){
                cout<<nbr;
            }
        }
    }
    void dfs_helper(unordered_map<int,bool> visited, int src){
        visited[src] = true;
        cout<<src<<" ";
        for(int nbr: l[src]){
            if(!visited[nbr]){
                dfs_helper(visited, nbr);
            }
        }
    }
    void dfs(int src){
        unordered_map<int,bool> visited;
        for(int i = 0; i < V; i++){
            visited[i] = false;
        }
        dfs_helper(visited,src);
    }
    
};

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 2);
    g.printAdjList();
    return 0;
}