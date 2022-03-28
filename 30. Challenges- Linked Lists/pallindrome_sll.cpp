//pallindrome check using sll
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

node * reverse(node *head){
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
    return head;
}

bool comparelists(node * head, node * rev){
    if(head == NULL){
        return true;
    }
    while(head != NULL and rev != NULL){
        if(head->data == rev->data){
            head=head->next;
            rev=rev->next;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    node * head = take_input(n);
    node * rev = reverse(head);
    comparelists(head, rev) ? cout<<"true" : cout<<"false";
    return 0;   
}