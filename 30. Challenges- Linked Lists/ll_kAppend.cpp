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
        cout<<head->data<<" ";
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

void kAppend(node *&head, int n, int k){ 
    if(k >= n){
        k = k%n;
    }
    if(k == 0 or head == NULL){
        return;
    }
    node * prev = NULL;
    node * curr = head;
    int jump = n-k;
    while(jump >= 1){
        prev = curr;
        curr = curr->next;
        jump--;
    }
    prev->next = NULL;
    node *temp = curr;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head;
    head = curr;
}

int main(){
    int n, k;
    cin>>n;
    node * head = take_input(n);
    cin>>k;
    kAppend(head, n, k);
    print(head);
    return 0;   
}