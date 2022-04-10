#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> calling;
    queue<int> ideal;
    int x, n;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>x;
        calling.push(x);
    }
    for(int i = 0; i < n; i++){
        cin>>x;
        ideal.push(x);
    }
    int time = n*1;
    for(int i = 0; i < n; i++){
        while(calling.front() != ideal.front()){
            int element = calling.front();
            calling.pop();
            calling.push(element);
            time += 1;
        }
        calling.pop();
        ideal.pop();
    }
    cout<<time;
    return 0;
}