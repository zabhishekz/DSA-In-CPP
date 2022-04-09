#include<iostream>
#include<deque>
using namespace std;

int main(){
    int n, k, a[100000];
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    cin>>k;

    //Process first k elements seperately
    deque <int> Q(k);
    int i;
    for(i = 0; i < k; i++){
        while(!Q.empty() && a[i]>a[Q.back()]){
            Q.pop_back();
        }
        Q.push_back(i);
    }

    //Process remaining elements
    for(; i < n; i++){
        cout<<a[Q.front()]<<" ";
        
        //1. remove the elements which are not the parts of window(Contraction)
        while(!Q.empty() and Q.front() <= i-k){
            Q.pop_front();
        }

        //2. remove the elements which are not useful and are in window
        while(!Q.empty() and a[i] >= a[Q.back()]){
            Q.pop_back();
        }

        //3. Add the new elements(Expansion)
        Q.push_back(i);
    }
    cout<<a[Q.front()]<<endl;
    
    return 0;
}