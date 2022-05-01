//We use postorder here NOT inorder
#include<iostream>
#include<queue>
#include<climits>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* insertInBST(node * root, int data){
    //base case
    if(root == NULL){
        return new node(data);
    }
    //rec case
    if(data <= root->data){
        root->left = insertInBST(root->left, data);
    }
    else{
       root->right = insertInBST(root->right, data); 
    }
    return root;
}

node* build(){
    //Read a list of numbers till -1 and also also these numbers will be inserted in the BST
    int d;
    cin>>d;
    node * root = NULL;

    while(d != -1){
        root = insertInBST(root, d);
        cin>>d;
    }
    return root;
}

void inorder(node * root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<", ";
    inorder(root->right);
}

class LinkedList{
    public:
    node*head;
    node*tail;
};

LinkedList flatten(node*root){
    LinkedList l;
    if(root==NULL){
        l.head = NULL;
        l.tail = NULL;
        return l;
    }
    //Leaf node
    if(root->left == NULL and root->right == NULL){
        l.head = l.tail = root;
        return l;
    }
    //Left is NOT null
    if(root->left != NULL and root->right == NULL){
        LinkedList leftLL = flatten(root->left);
        leftLL.tail->right = root;

        l.head = leftLL.head;
        l.tail = root;
        return l;
    }
    //Right is NOT null
    if(root->left == NULL and root->right != NULL){
        LinkedList rightLL = flatten(root->right);
        root->right = rightLL.head;

        l.head = root;
        l.tail = rightLL.tail;
        return l;
    }
    //Both sides are not NULL
    LinkedList leftLL = flatten(root->left);
    LinkedList rightLL = flatten(root->right);

    leftLL.tail->right = root;
    root->right = rightLL.head;
    l.head = leftLL.head;
    l.tail = rightLL.tail;
    return l;
}

int main(){
    node * root = build();
    inorder(root);
    cout<<endl;
    LinkedList l = flatten(root);
    node*temp = l.head;
    while(temp!=NULL){
        cout<<temp->data<<"--->";
        temp = temp->right;
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    return 0;
}    