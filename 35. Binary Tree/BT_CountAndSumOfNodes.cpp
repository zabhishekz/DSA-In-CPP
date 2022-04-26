/*Binary tree
Count number of nodes
Sum of nodes

             8
           /   \
         10     3
        /  \     \
       1    6     14
           / \    /
          9   7  13
Input  : 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1 
Output : Count = 9
         Sum = 71
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

int count(node *root){
    if(root == NULL){
        return 0;
    }
    int ls = count(root->left);
    int rs = count(root->right);
    return ls+rs+1;
}

int sum(node *root){
    if(root == NULL){
        return 0;
    }
    int ls = sum(root->left);
    int rs = sum(root->right);
    return (root->data)+(ls)+(rs);
}

int main(){
    node * root = buildtree();
    cout<<"Count = "<<count(root)<<endl;
    cout<<"Sum = "<<sum(root);
    return 0;
}