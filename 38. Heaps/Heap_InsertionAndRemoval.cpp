//Heap/Priority Queue USing vector
#include<iostream>
#include<vector>
using namespace std;

class Heap{
    vector<int> v;
    bool minHeap;
    bool compare(int a, int b){
        if(minHeap==true){
            return a<b;
        }
        else{
            return a>b;
        }
    }
    void heapify(int idx){
        int left = 2*idx;
        int right = left+1;

        int min_idx = idx;
        int last = v.size()-1;
        if(left <= last && compare(v[left], v[min_idx])){
            min_idx = left;
        }
        if(right <= last && compare(v[right], v[min_idx])){
            min_idx = right;
        }
        if(min_idx != idx){
            swap(v[min_idx], v[idx]);
            heapify(min_idx);
        }
    }
public:
    Heap(int default_size = 10, bool type = true){
        v.reserve(default_size);
        v.push_back(-1);// blocking 0th index
        minHeap = type;//true-minHeap//false-maxHeap 
    }
    void push(int d){
        v.push_back(d);
        int idx = v.size()-1;
        int parent = idx/2;

        //keep pushing to the top till u reach root node or stop midway because current element is already greater than parent
        while(idx > 1 and compare(v[idx], v[parent])){
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent/2;
        }
    }
    int top(){
        return v[1];
    }
    void pop(){
        int last_idx = v.size()-1;
        swap(v[1], v[last_idx]);
        v.pop_back();
        heapify(1);
    }
    bool empty(){
        return v.size() == 1;
    }
};

int main(){
    //minHeap 
    Heap h;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int no;
        cin>>no;
        h.push(no);
    }
    while(!h.empty()){
        cout<<h.top()<<" ";
        h.pop();
    }
    cout<<endl<<endl;
    //maxHeap
    Heap h2(10, false);
    cin>>n;
    for(int i = 0; i < n; i++){
        int no;
        cin>>no;
        h2.push(no);
    }
    while(!h2.empty()){
        cout<<h2.top()<<" ";
        h2.pop();
    }
    return 0;
}