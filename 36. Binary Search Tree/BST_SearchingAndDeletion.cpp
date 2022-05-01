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

bool search(node * root, int data){
    //base case
    if(root == NULL){
        return false;
    }
    if(root->data == data){
        return true;
    }
    //rec case
    if(data < root->data){
        return search(root->left, data);
    }
    else{
        return search(root->right, data);
    }
    
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

node * deleteInBST(node*root, int data){
    if(root == NULL){
        return NULL;
    }
    else if(data < root->data){
        root->left = deleteInBST(root->left, data);
        return root;
    }
    else if(data == root->data){
        //Found the node to delete - 3 cases
        //1.Node has 0 child- leaf node
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        //2.Node has 1 children
        if(root->left == NULL && root->right != NULL){
            node * temp = root->right;
            delete root;
            return temp;
        }
        if(root->left != NULL && root->right == NULL){
            node * temp = root->left;
            delete root;
            return temp;
        }
        //3.Node has 2 children
        //Find inorder successor
        node * replace = root->right;
        while( replace->left!=NULL){
            replace = replace->left;
        }
        root->data = replace->data;
        root->right = deleteInBST(root->right, replace->data);
        return root;
    }
    else{
        root->right = deleteInBST(root->right, data);
        return root;
    }
}

int main(){
    node * root = build();
    inorder(root);
    cout<<endl;

    int s;
    cin>>s;
    root = deleteInBST(root, s);
    inorder(root);
    cout<<endl;
    bfs2(root);
    return 0;
}