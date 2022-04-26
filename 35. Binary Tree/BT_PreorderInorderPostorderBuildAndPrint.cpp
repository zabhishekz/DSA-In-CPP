/*
Binary Tree
Preorder- root, left, right
Inorder- left, root, right
Postorder- left, right, root

             8
           /   \
         10     3
        /  \     \
       1    6     14
           / \    /
          9   7  13

Input  : 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1 
Output :
        Preorder  - 8 10 1 6 9 7 3 14 13
        Inorder   - 1 10 9 6 7 8 3 13 14
        Postorder - 1 9 7 6 10 13 14 3 8
*/
#include<iostream>
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

void print_preorder(node * root){
    if(root == NULL){
        return;
    }
    //Preorder- root, left, right
    cout<<root->data<<" ";
    print_preorder(root->left);
    print_preorder(root->right);
}

void print_inorder(node * root){
    if(root == NULL){
        return;
    }
    //Inorder- left, root, right
    print_inorder(root->left);
    cout<<root->data<<" ";
    print_inorder(root->right);
}

void print_postorder(node * root){
    if(root == NULL){
        return;
    }
    //Postorder- left, right, root
    print_postorder(root->left);
    print_postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    node * root = buildtree();
    print_preorder(root);
    cout<<endl;
    print_inorder(root);
    cout<<endl;
    print_postorder(root);
    cout<<endl;
    return 0;
}