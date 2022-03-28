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

node * evenafterodd(node *head){ 
    if(head == NULL){
        return NULL;
    }
    node * odd = NULL;
    node * even = NULL;
    while(head != NULL){
        if((head->data)%2 == 0){
            insertAtTail(even, head->data);
        }
        else{
            insertAtTail(odd, head->data);
        }
        head = head->next;
    }
    node *ptr = odd;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = even;
    return odd;
}

int main(){
    int n;
    cin>>n;
    node * head = take_input(n);
    node * head2 = evenafterodd(head);
    print(head2);
    return 0;   
}