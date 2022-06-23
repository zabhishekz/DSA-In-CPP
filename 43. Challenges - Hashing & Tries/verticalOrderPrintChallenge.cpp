#include<iostream>
#include<queue>
#include<map>
using namespace std;
class node {
public:
    int data;
    node* left, * right;
    node(int d) {
        data = d;
        left = right = NULL;
    }
};

node* BuildTree() {
    int d;
    cin >> d;
    if (d == -1){
        return NULL;
    }      
    node* root = new node(d);
    queue<node*>q;
    q.push(root);
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        int lc, rc;
        cin >> lc >> rc;
        if (lc != -1) {
            temp->left = new node(lc);
            q.push(temp->left);
        }
        if (rc != -1) {
            temp->right = new node(rc);
            q.push(temp->right);
        }
    }
    return root;
}

void verticalOrderPrint(node * root, int d, map<int, vector<int>> &m){
    //base case
    if(root == NULL){
        return;
    }
    m[d].push_back(root->data);
    verticalOrderPrint(root->left, d-1, m);
    verticalOrderPrint(root->right, d+1, m);
    return;
}

int main() {
    int l;
    cin>>l;
    node* root = NULL;
    root = BuildTree();
    map<int, vector<int>> m;
    int d = 0;  
    verticalOrderPrint(root, d, m);

    for(auto p: m){
        for(int x : p.second){
            cout<<x<<" ";
        }
        cout<<endl;
    }  
    return 0;
}
