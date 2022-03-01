// Mid point of a linked list
// Runner technique
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

int main(){
    node * head;
    cin>>head;
    cout<<head;
    node * mid = midpoint(head);
    cout<<mid->data<<endl ;
    return 0;   
}