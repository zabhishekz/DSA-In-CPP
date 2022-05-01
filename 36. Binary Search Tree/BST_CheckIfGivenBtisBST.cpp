//Using top-down approach, each node data sould be in its range
#include<iostream>
#include<queue>
#include<climits>
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

void inorder(node * root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<", ";
    inorder(root->right);
}

bool isBST(node * root, int minv = INT_MIN, int maxv = INT_MAX){
    if(root == NULL){
        return true;
    }
    if(root->data >= minv && root->data<=maxv && isBST(root->left,minv,root->data) && isBST(root->right,root->data, maxv)){
        return true;
    }
    return false;
}

int main(){
    node * root = build();
    inorder(root);
    cout<<endl;

    if(isBST(root)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}