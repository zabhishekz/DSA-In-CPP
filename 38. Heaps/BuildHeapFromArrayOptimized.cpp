//Converting Array(or vector) into Heap(Optimized approach O(N))
//Bottom up approach
#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> v){
    for(int x: v){
        cout<<x<<" ";
    }
    cout<<endl;
}

bool minHeap = false;
bool compare(int a, int b){
    if(minHeap==true){
        return a<b;
    }
    else{
        return a>b;
    }
}

void heapify(vector <int> &v, int idx){
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
        heapify(v, min_idx);
    }
}

//maxHeap here
void buildHeapOpt(vector<int> &v){
    for(int i = (v.size()-1)/2; i >=1; i--){
        heapify(v, i);
    }
}

int main(){
    vector<int> v {-1, 10, 20, 5, 6, 1, 8, 9, 4};
    print(v);
    cout<<endl;
    buildHeapOpt(v);
    print(v);
    cout<<endl; 

    return 0;
}