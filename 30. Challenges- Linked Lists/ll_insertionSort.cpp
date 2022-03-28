#include<iostream>
using namespace std;

class node{
public:
    int data;
    node *next;
    node *prev;

    node(int d){
        data = d;
        next = NULL;
        prev = NULL;
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
    tail->next->prev = tail;
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

void insertionSort(node *&head){ 
    if(head == NULL || head->next == NULL){
        return;
    }
    node *i = head->next;
    node *j;
    node *k = NULL;
    int key;
    while(i != NULL){
        key = i->data;
        j = i->prev;
        while(j != NULL  and (j->data) > key){
            j->next->data = j->data;
            k = j;
            j = j->prev;
        }
        if(j != NULL){
            j->next->data = key;
            i = i->next;
        }
        else{
            k->data = key;
            i = i->next;
        }
    }
}

int main(){
    int n;
    cin>>n;
    node * head = take_input(n);
    insertionSort(head);
    print(head);
    return 0;   
}