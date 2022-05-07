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

node *buildtreeLevel()
{
    int d;
    cin>>d;
    queue<node *>q;
    node *root = new node(d);
    q.push(root);
    int c1,c2;
    while(!q.empty())
    {
        node *f = q.front();
        q.pop();
        cin>>c1>>c2;
        if(c1!=-1)
        {
            f->left = new node(c1);
            q.push(f->left);
        }
        if(c2 != -1)
        {
            f->right = new node(c2);
            q.push(f->right);
        }
    }
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
    node * root = buildtreeLevel();
    int maxlevel = -1;
    printRightView(root, 0, maxlevel);
    return 0;
}