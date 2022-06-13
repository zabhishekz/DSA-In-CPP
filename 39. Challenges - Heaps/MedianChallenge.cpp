#include<iostream>
#include<queue>
using namespace std;

int main(){

    int t, n, arr[10000];
    cin>>t;
    while(t != 0){
        priority_queue<int> leftheap;//maxheap
        priority_queue<int, vector<int>, greater<int>> rightheap;//miheap
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        int j = 0;
        int d = arr[j];
        leftheap.push(d);
        float med = d;
        cout<<(int)med<<" ";
        j++;

        d = arr[j];
        while (j != n){
            if(leftheap.size() > rightheap.size()){
                if(d < med){
                    rightheap.push(leftheap.top());
                    leftheap.pop();
                    leftheap.push(d);
                }
                else{
                    rightheap.push(d);
                }
                med = (leftheap.top()+rightheap.top())/2.0;
            }
            else if(leftheap.size() == rightheap.size()){
                if(d<med){
                    leftheap.push(d);
                    med = leftheap.top();
                }
                else{
                    rightheap.push(d);
                    med = rightheap.top();
                }
            }
            else{
                if(d > med){
                    leftheap.push(rightheap.top());
                    rightheap.pop();
                    rightheap.push(d);
                }
                else{
                    leftheap.push(d);
                }
                med = (leftheap.top()+rightheap.top())/2.0;
            }
            cout<<(int)med<<" ";
            j++;
            d = arr[j];
        }
        cout<<endl;
        t--;
    }
    return 0;
}