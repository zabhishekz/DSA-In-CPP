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

void insertAtTail(node* &head, int d){
    node *n = new node(d);
    if(head == NULL){
        head = n;
        return;
    }
    node *tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = n;
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}

node* merge(node*&head1, node*&head2){
    node*p1 = head1;
    node*p2 = head2;
    node*head3 = new node(-1);
    node*p3 = head3;
    while(p1 != NULL and p2 != NULL){
        if(p1->data < p2->data){
            p3->next = p1;
            p1=p1->next;
        }
        else{
            p3->next = p2;
            p2=p2->next;
        }
        p3 = p3->next;
    }
    while(p1 != NULL){
        p3->next = p1;
        p1=p1->next;
        p3 = p3->next;
    }
    while(p2 != NULL){
        p3->next = p2;
        p2=p2->next;
        p3 = p3->next;
    }
    return head3->next;
}

int main(){
    node * head1 = NULL;
    insertAtTail(head1,1);
    insertAtTail(head1,4);
    insertAtTail(head1,6);
    insertAtTail(head1,9);
    node * head2 = NULL;
    insertAtTail(head2,0);
    insertAtTail(head2,2);
    insertAtTail(head2,5);
    insertAtTail(head2,10);
    display(head1);
    display(head2);
    node*head3 = merge(head1,head2);
    display(head3);
    return 0;
}