#include<iostream>
using namespace std;
int sum = 0;

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
    int d,c;
    cin>>d;
    node* root = new node(d);
    cin>>c;
    if(c == 2){
        root->left = buildtree();
        root->right = buildtree();
    }
    else if(c == 1){
        root->left = buildtree();
    }
    return root;
}

//funtion to print kth level of tree
void sumKthLevel(node* root, int k){
    if(root == NULL){
        return;
    }
    if(k == 0){
        sum += (root->data);
        return;
    }
    sumKthLevel(root->left, k-1);
    sumKthLevel(root->right, k-1);
    return;
}

int main(){
    node * root = buildtree();
    int l;
    cin>>l;
    sumKthLevel(root, l);
    cout<<sum;
    return 0;
}