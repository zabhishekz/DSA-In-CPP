#include<iostream>
#include<unordered_map>
#include<list>
#include<climits>
#include<set>
using namespace std;

template<typename T>
class Graph{
    unordered_map<T, list<pair<T, int>> > m;
public:
    void addEdge(T u, T v, int dist, bool bidir = true){
        m[u].push_back(make_pair(v, dist));
        if(bidir){
            m[v].push_back(make_pair(u, dist));
        }
    }
    void printAdj(){
        for(auto j : m){
            cout<<j.first<<"->";
            for(auto l : j.second){
                cout<<"("<<l.first<<", "<<l.second<<")";
            }
            cout<<endl;
        }
    }
    void dijsktraSSSP(T src){
        unordered_map<T, int> dist;
        for(auto j : m){
            dist[j.first] = INT_MAX;
        }
        //make a set to find out a node with minimum distance
        set<pair<int, T>> s;
        dist[src] = 0;
        s.insert(make_pair(0, src));
        while(!s.empty()){
            //find pair at the front
            auto p = *(s.begin());
            T node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());

            //iterate over neigbours/ children of the current node
            for(auto childPair : m[node]){
                if(nodeDist + childPair.second < dist[childPair.first]){
                    //in set udation not possible
                    //simulate updation by removing old pair and insert new pair
                    T dest = childPair.first;

                    auto f = s.find(make_pair(dist[dest], dest));
                    if(f != s.end()){
                        s.erase(f);
                    }
                    //insert new pair
                    dist[dest] = nodeDist+childPair.second;
                    s.insert(make_pair(dist[dest],dest)); 
                }
            }
        }
        //Lets print distances to all other nodes from src
        for(auto d : dist){
            cout<<d.first<<" is located at distance of "<<d.second<<endl;
        }
    }
};

int main(){
    Graph<int> g;
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 2);
    g.addEdge(1, 4, 7);
    //g.printAdj();
    g.dijsktraSSSP(1);

    // Graph<string> india;
    // india.addEdge("Amritsar", "Delhi", 1);
    // india.addEdge("Amritsar", "Jaipur", 4);
    // india.addEdge("Jaipur", "Delhi", 2);
    // india.addEdge("Jaipur", "Mumbai", 8);
    // india.addEdge("Bhopal", "Agra", 2);
    // india.addEdge("Mumbai", "Bhopal", 3);
    // india.addEdge("Agra", "Delhi", 1);
    // india.printAdj();
    return 0;
}