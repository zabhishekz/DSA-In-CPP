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

node* buildtreeFromArray(int *a, int s, int e){
    if(s > e){
        return NULL;
    }
    int mid = (s+e)/2;
    node* root = new node(a[mid]);
    root->left = buildtreeFromArray(a, s, mid-1);
    root->right = buildtreeFromArray(a, mid+1, e);
    return root;
}

void preorder(node * root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    int t, n, arr[10];
    cin>>t;
    while(t!=0){
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        node*root = buildtreeFromArray(arr, 0, n-1);
        preorder(root);
        t--;
    }
    return 0;
}
