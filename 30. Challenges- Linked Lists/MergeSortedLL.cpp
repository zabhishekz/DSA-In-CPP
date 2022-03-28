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
	int num = 0;
    int d;
    node * head = NULL;
    //take input until input is -1
    while(num < n){
		cin>>d;
        insertAtTail(head, d);
		num++;
    }
    return head;
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
int main(){
	int t, n1, n2;
	cin>>t;
	node * head;
    node * head2;
	while(t--){
	cin>>n1;
    head = take_input(n1);
	cin>>n2;
	head2 = take_input(n2);
    node *newHead = merge(head, head2);
    print(newHead);
	}
    return 0;   
}