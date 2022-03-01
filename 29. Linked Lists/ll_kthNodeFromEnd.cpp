// kth node form end in single pass
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

node* kthnode(node*head, int k){
    if(head->next == NULL || head == NULL){
        return head;
    }
    node*slow = head;
    node*fast = head;
    //take k-1 jumps;
    int jump = 1;
    while(fast != NULL){
        if(jump<=k){
        fast = fast->next;
        jump++;
        }
        else{
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

int main(){
    node * head;
    cin>>head;
    cout<<head;
    int k;
    cout<<"Enter k = ";
    cin>>k;
    node * knode = kthnode(head, k);
    cout<<knode->data<<endl ;
    return 0;   
}