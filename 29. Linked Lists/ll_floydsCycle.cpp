//a. Whether a given linked list contains a cycle or not
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

bool detectCycle(node*head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node*slow = head;
    node*fast = head;
    while(fast != NULL and fast->next != NULL ){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            return true;
        }
    }
    return false;
}

int main(){
    node* head;
    cin>>head;
    cout<<head;
    if(detectCycle(head)){
        cout<<"Linked List contains a cycle";
    }
    else{
        cout<<"Linked List does NOT contains a cycle";
    }
    return 0;   
}