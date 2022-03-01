// Merge two sorted linked list into one
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


node* merge(node*a, node*b){
    if(a == NULL){
        return b;
    }
    if(b == NULL){
        return a;
    }
    node*c;
    if(a->data <= b->data){
        c = a;
        c->next = merge(a->next, b); 
    }
    else{
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

node* midpoint(node*head){
    if(head->next == NULL || head == NULL){
        return head;
    }
    node*slow = head;
    node*fast = head->next;
    while(fast != NULL and fast->next != NULL ){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node* mergeSort(node*head){
    if(head == NULL or head->next == NULL){
        return head;
    }
    node *mid = midpoint(head);
    node *a = head;
    node *b = mid->next; 
    mid->next = NULL;

    a = mergeSort(a);
    b = mergeSort(b);

    node *c = merge(a, b);
    return c; 
}

int main(){
    node* head;
    cin>>head;
    cout<<head;
    head = mergeSort(head);
    cout<<head<<endl;
    return 0;   
}