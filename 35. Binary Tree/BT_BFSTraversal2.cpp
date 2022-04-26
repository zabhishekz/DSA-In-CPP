/*Binary tree
BFS traversal2-
Similar to BFS traversal in O(n) but here there is separation between levels in output 

             8
           /   \
         10     3
        /  \     \
       1    6     14
           / \    /
          9   7  13
Input  : 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1 
Output : 
        8,
        10, 3, 
        1, 6, 14, 
        9, 7, 13
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

void bfs2(node * root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node * f = q.front();
        if(f == NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<", ";
            q.pop();

            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return;
}

void bfs2(node * root){
    queue<node*>  q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node * f = q.front();
        if(f == NULL){

        }
        else{
            cout<<f->data;
            q.pop();
            if(f->left){
                q.push(f->left;)
            }
        }
    }
}

int main(){
    node * root = buildtree();
    bfs2(root);
    return 0;
}