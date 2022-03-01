//Reverse a linked list
//Recursively Reverse a linked list
#include<iostream>
using namespace std;

class node{
public:
    int data;
    node *next;

    node(int d){
        data = d;
        next = NULL;
    }
};

void insertAtHead(node *&head, int d){
    if(head == NULL){
        head = new node(d);
        return;
    }
    node *n = new node(d);
    n->next = head;
    head = n;
}

void print(node *head){
    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}

node* take_input(){
    int d;
    cin>>d;
    node * head = NULL;
    //take input until input is -1
    while(d != -1){
        insertAtHead(head, d);
        cin>>d;
    }
    return head;
}

ostream& operator<<(ostream &os, node *head){
    print(head);
    return os;//cout
}

istream& operator>>(istream &is, node *&head){
    head = take_input();
    return is;
}
//iterative approach O(n) time + O(1) space---->more efficient 
void reverse(node*&head){
    node *c = head;
    node *p = NULL;
    node *n;
    while(c != NULL){
        n = c->next; // save the next node
        c->next = p; // make the current point to prev
        p = c;//update p
        c = n;//update c
    }
    head = p; 
}
//recursive approach O(n) time + O(n) stack space
node * reverseRecursive(node *head){
    if(head->next == NULL || head == NULL){
        return head;
    }
    node *shead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return shead;
}

int main(){
    node * head;
    cin>>head;
    cout<<head;
    reverse(head);
    cout<<head;
    head = reverseRecursive(head);
    cout<<head;
    return 0;   
}