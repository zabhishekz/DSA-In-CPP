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

node* buildtree(){
    int d;
    cin>>d;
    if(d == -1){
        return NULL;
    }
    node* root = new node(d);
    root->left = buildtree();
    root->right = buildtree();
    return root;
}

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

int sumReplacement(node * root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL and root->right == NULL){
        return root->data;
    }
    int ls = sumReplacement(root->left);
    int rs = sumReplacement(root->right);
    int temp = root->data;
    root->data = ls+rs;
    return temp+root->data;
}

int main(){
    node * root = buildtree();
    bfs(root);
    sumReplacement(root);
    cout<<endl;
    bfs(root);
    return 0;
}