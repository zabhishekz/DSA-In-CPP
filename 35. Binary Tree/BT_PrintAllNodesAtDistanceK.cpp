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

void printAtLevelK(node* root, int k){
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout<<root->data<<" ";
        return;
    }
    printAtLevelK(root->left, k-1);
    printAtLevelK(root->right, k-1);
    return;
}

int prinAtDistanceK(node*root, node*target, int k){
    //base case
    if(root == NULL){
        return -1;
    }

    //reach the target node
    if(root == target){
        printAtLevelK(target, k);
        return 0;
    }

    int DL = prinAtDistanceK(root->left, target, k);
    if(DL != -1){
        if(DL+1 == k){
            cout<<root->data<<" "; 
        }
        else{
            printAtLevelK(root->right, k-2-DL);
        }
        return 1+DL;
    }

    int DR = prinAtDistanceK(root->right, target, k);
    if(DR != -1){
        if(DR+1 == k){
            cout<<root->data<<" "; 
        }
        else{
            printAtLevelK(root->left, k-2-DR);
        }
        return 1+DR;
    }
    return -1;
}

int main(){
    node * root = buildtree();
    node * target = root->left->left;
    prinAtDistanceK (root, target, 2);
    return 0;
}