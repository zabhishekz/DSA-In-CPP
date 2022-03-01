#include<iostream>
#include<list>
using namespace std;

int main(){
    list < pair<int, int> > l1; //creates a single list
    list < pair<int, int> > l2[5]; //creates an array of 5 lists
    list < pair<int, int> > *l;
    int n;
    cin>>n;
    l = new list <pair<int, int> > [n];
    int e;
    cin>>e;
    for(int i = 0; i < e; i++){
        int x, y, wt;
        cin>>x>>y>>wt;
        l[x].push_back(make_pair(y, wt));
        l[y].push_back(make_pair(x, wt));//biderectional edges
    }

    //print
    for(int i = 0; i < n; i++){
        //print every linked list
        cout<<"Linked List "<<i<<"->";
        for(auto xp: l[i]){
            cout<<"("<<xp.first<<","<<xp.second<<"), ";
        }
        cout<<endl;
    }
    return 0;
}
