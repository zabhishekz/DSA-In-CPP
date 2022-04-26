/*Binary tree
Diameter of a tree
             8
           /   \
         10     3
        /  \     \
       1    6     14
           / \    /
          9   7  13
Input  : 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1 
Output : diameter = 6
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

int height(node *root){
    if(root == NULL){
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls, rs)+1;
}

int diameter(node *root){//O(n^2)
    if(root == NULL){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    int op1 = h1+h2;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);
    return max(op1, max(op2, op3));
}

//optimised approach- bottom to up
class Pair{
    public:
    int height;
    int diameter;
};

Pair fastDiameter(node *root){
    Pair p;
    if(root == NULL){
        p.diameter = p.height = 0;
        return p;
    }
    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right); 
    p.height = max(left.height, right.height)+1;
    p.diameter = max(left.height+right.height, max(left.diameter, right.diameter));
    return p;
}

int main(){
    node * root = buildtree();
    cout<<"Diameter = "<<diameter(root)<<endl;

    Pair p = fastDiameter(root);
    cout<<"Height = "<<p.height<<endl;
    cout<<"Diameter = "<<p.diameter;
    return 0;
}