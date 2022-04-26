#include<iostream>
#include<queue>
using namespace std;
//Input : 1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1
//Output: 1 3 5 9 11 
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

void printRightView(node * root, int level ,int &maxlevel){
    if(root == NULL){
        return;
    }
    if(maxlevel<level){
        cout<<root->data<<" ";
        maxlevel = level;
    }
    printRightView(root->right, level+1, maxlevel);
    printRightView(root->left, level+1, maxlevel);

}

int main(){
    node * root = buildtree();
    int maxlevel = -1;
    printRightView(root, 0, maxlevel);
    return 0;
}