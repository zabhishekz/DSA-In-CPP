#include<iostream>
#include<map>
#include<list>
#include<climits>
#include<queue>
using namespace std;

template<typename T>
class Graph{
    map<T, list<T>> l;
public:
    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void dfs_helper(T src, map<T, bool> &visited){
        //Recursive func that will traverse graph
        cout<<src<<" ";
        visited[src] = true;
        //go to any any unvisited neighbor of node
        for(T nbr: l[src]){
            if(!visited[nbr]){
                dfs_helper(nbr, visited);
            }
        }
    }
    void dfs(){
        map<T, bool> visited;
        //mark all nodes as not visitred in beginning
        for(auto p: l){
            T node = p.first;
            visited[node] = false;
        }
        //iterate over all the vertices and init a dfs call
        int cnt = 0;
        for(auto  p : l){
            T node = p.first;
            if(!visited[node]){
                cout<<"Component "<<cnt<<" -->";
                dfs_helper(node, visited);
                cnt++;
                cout<<endl;
            }
        }
    }
};

int main(){
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 3);
    g.addEdge(0, 4);

    g.addEdge(5, 6);
    g.addEdge(6, 7);

    g.addEdge(8, 8);
    g.dfs();
    return 0;
}