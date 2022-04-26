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

//finding the level of a node from a given node
int search(node* root, int key, int level){
    if(root == NULL){
        return -1;
    }
    if(root->data == key){
        return level;
    }
    int left = search(root->left, key, level+1);
    if(left != -1){
        return left;
    }
    return search(root->right, key , level+1);
}

//function to find distance between any 2 nodes
int findDistance(node* root, int a, int b){
    node * lca_node = lca(root, a, b);
    int l1 = search(lca_node, a, 0);
    int l2 = search(lca_node, b, 0);
    return l1+l2;
}

int main(){
    node * root = buildtree();
    cout<<"Distance of 4 and 7 is "<<findDistance(root, 4, 7)<<endl;
    cout<<"Distance of 6 and 9 is "<<findDistance(root, 6, 9)<<endl;
    return 0;
}
