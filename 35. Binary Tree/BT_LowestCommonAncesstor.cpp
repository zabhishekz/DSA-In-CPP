#include<iostream>
using namespace std;

//Input: 1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1

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


//assumption- both a and b are present in the tree, all keys are node
node *lca(node* root, int a, int b){
    //base case
    if(root == NULL){
        return NULL;
    }

    if(root->data == a or root->data == b){
        return root;
    }

    //search in left and right subtree
    node * leftans = lca(root->left, a, b);
    node * rightans = lca(root->right, a, b);
    if(leftans != NULL and rightans != NULL){
        return root;
    }
    if(leftans != NULL){
        return leftans;
    }
    return rightans;
}

int main(){
    node * root = buildtree();
    cout<<"LCA of 4 and 7 is "<<lca(root, 4, 7)->data<<endl;
    cout<<"LCA of 6 and 9 is "<<lca(root, 6, 9)->data<<endl;
    return 0;
}