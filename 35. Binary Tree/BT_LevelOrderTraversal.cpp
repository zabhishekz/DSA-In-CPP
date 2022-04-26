/*Binary tree
1. Height of tree
2. Level Order traversal - Traverse each level in recursive manner in o(n)
             8
           /   \
         10     3
        /  \     \
       1    6     14
           / \    /
          9   7  13

Input  : 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1 
Output : 
        8
        10 3
        1 6 14
        9 7 13
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

//function to return height of tree
int height(node *root){
    if(root == NULL){
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls, rs)+1;
}

//funtion to print kth level of tree
void printkthLevel(node* root, int k){
    if(root == NULL){
        return;
    }
    if(k == 1){
        cout<<root->data<<" ";
        return;
    }
    printkthLevel(root->left, k-1);
    printkthLevel(root->right, k-1);
    return;
}

//function to print all levels of tree
void printALLlevels(node * root){
    int h = height(root);
    for(int i = 1; i <= h; i++){
        printkthLevel(root, i);
        cout<<endl;
    }
}

int main(){
    node * root = buildtree();
    cout<<"Height of the tree is "<<height(root)<<endl;
    printALLlevels(root);
    return 0;
}