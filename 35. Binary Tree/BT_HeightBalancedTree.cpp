//Height Balanced Tree: |h1-h2| <= 1 at every node
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

class HBPair{
public:
    int height;
    bool balance;
};

//Function to check if a tree is height balanced or not
HBPair isHeightBalanced(node *root){
    HBPair p;
    if(root == NULL){
        p.height = 0;
        p.balance = true;
        return p;
    }
    HBPair left = isHeightBalanced(root->left);
    HBPair right = isHeightBalanced(root->right);
    p.height = max(left.height, right.height)+1;
    if(std::abs(left.height-right.height)<= 1 and left.balance and right.balance){
        p.balance = true;
    }
    else{
        p.balance = false;
    }
    return p;
}

int main(){
    node * root = buildtree();
    HBPair h = isHeightBalanced(root);
    cout<<h.balance;
    return 0;
}