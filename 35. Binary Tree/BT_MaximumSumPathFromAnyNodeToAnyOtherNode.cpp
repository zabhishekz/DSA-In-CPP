#include<iostream>
using namespace std;

//Input: 10 2 20 -1 -1 1 -1 -1 10 -1 -25 3 -1 -1 4 -1 -1
//output = 42x

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

class Pair{
public:
    int branchsum;
    int maxsum;
    Pair(){
        branchsum = 0;
        maxsum = 0;
    }
};

Pair maxSumPath(node* root){
    Pair p;
    if(root == NULL){
        return p;
    }
    Pair left = maxSumPath(root->left);
    Pair right = maxSumPath(root->right); 

    int op1 = root->data;
    int op2 = root->data + left.branchsum;
    int op3 = root->data + right.branchsum;
    int op4 = root->data + left.branchsum + right.branchsum;

    int current_ans_through_root = max(op1,max(op2, max(op3, op4)));

    //branch sum for the current root node
    p.branchsum= max(left.branchsum, max(right.branchsum, 0)) + root->data;
    p.maxsum = max(left.maxsum, max(right.maxsum, current_ans_through_root));
    return p;
}

int main(){
    node * root = buildtree();
    cout<<"Max Sum Path "<<maxSumPath(root).maxsum<<endl;   
    return 0;
}