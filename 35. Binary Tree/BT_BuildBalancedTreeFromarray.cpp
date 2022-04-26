#include<iostream>
#include<queue>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;    
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

void bfs(node * root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node * f = q.front();
        cout<<f->data<<", ";
        q.pop();

        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
    }
    return;
}

node* buildtreeFromArray(int *a, int s, int e){
    if(s > e){
        return NULL;
    }
    int mid = (s+e)/2;
    node* root = new node(a[mid]);
    root->left = buildtreeFromArray(a, s, mid-1);
    root->right = buildtreeFromArray(a, mid+1, e);
    return root;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    node*root = buildtreeFromArray(arr, 0,n-1);
    bfs(root);
    return 0;
}