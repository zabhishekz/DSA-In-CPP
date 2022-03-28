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

void insertAtTail(node *&head, int d){
    if(head == NULL){
        head = new node(d);
        return;
    }
    node *tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = new node(d);
    return;
}

void print(node *head){
    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}

node* take_input(int n){
    int d;
    node * head = NULL;
    while(n > 0){
        cin>>d;
        insertAtTail(head, d);
        n--;
    }
    return head;
}

node * reverseRecursive(node *head, int k){ 
    int x = k;
    node *c = head;
    node *p = NULL;
    node *n = NULL;
    while(c != NULL && x > 0){
        n = c->next;
        c->next = p;
        p = c;
        c = n;
        x--;
    }
    if(n != NULL){
        head->next = reverseRecursive(n, k);
    }
    return p;
}

int main(){
    int n, k;
    cin>>n>>k;
    node * head = take_input(n);
    head = reverseRecursive(head, k);
    print(head);
    return 0;   
}