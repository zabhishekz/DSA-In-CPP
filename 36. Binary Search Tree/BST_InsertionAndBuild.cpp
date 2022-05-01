#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

//accepts old root node and data and returns new root node
node* insertInBST(node * root, int data){
    //base case
    if(root == NULL){
        return new node(data);
    }
    //rec case
    if(data <= root->data){
        root->left = insertInBST(root->left, data);
    }
    else{
       root->right = insertInBST(root->right, data); 
    }
    return root;
}

node* build(){
    //Read a list of numbers till -1 and also also these numbers will be inserted in the BST
    int d;
    cin>>d;
    node * root = NULL;

    while(d != -1){
        root = insertInBST(root, d);
        cin>>d;
    }
    return root;
}

void bfs2(node * root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node * f = q.front();
        if(f == NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<", ";
            q.pop();

            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return;
}

void inorder(node * root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<", ";
    inorder(root->right);
}

int main(){
    node * root = build();
    inorder(root);
    cout<<endl;
    bfs2(root);
    return 0;
}

//inorder of a BST is always a sorted output