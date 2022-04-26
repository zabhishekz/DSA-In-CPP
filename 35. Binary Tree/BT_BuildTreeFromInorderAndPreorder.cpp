/*Build Binary tree from inorder and preorder traversal
Preoreder : 1 2 3 4 8 5 6 7
Inorder   : 3 2 8 4 1 6 7 5
Pre+In  -> Only 1 Unique BT
Post+In -> Only 1 Unique BT
*/
#include<iostream>
#include<queue>
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

node * createTreeFromTrav(int *in, int *pre, int s, int e){
    static int i = 0;
    //Base Case
    if(s > e){
        return NULL;
    }

    //Rec Case
    node * root = new node(pre[i]);
    int index = -1;
    for(int j = s; j<=e; j++){
        if(in[j]==pre[i]){
            index = j;
            break;
        }
    }
    i++;
    root->left  = createTreeFromTrav(in, pre, s, index-1);
    root->right = createTreeFromTrav(in, pre, index+1, e);
    return root;
}

void bfs(node * root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node * f = q.front();
        cout<<f->data<<", ";
        q.pop();

        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
    }
    return;
}

int main(){
    int in[] = {3, 2, 8, 4, 1, 6, 7, 5};
    int pre[] = {1, 2, 3, 4, 8, 5, 6, 7}; 
    int n = sizeof(in)/sizeof(int);
    node * root = createTreeFromTrav(in, pre, 0, n-1);
    bfs(root);      
}