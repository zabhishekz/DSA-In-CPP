//Basic operations
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

//passing head pointer by reference- we want to update head value with function
void insertAtHead(node *&head, int d){
    if(head == NULL){
        head = new node(d);
        head->next = head;
        return;
    }
    node *temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    node *n = new node(d);
    temp->next = n;
    n->next = head;
    head = n;
}

int length(node *head){
    if(head == NULL)
    {
        return 0;
    }
    int cnt = 1;
    node* tmp = head;
    while(tmp->next != head){
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}

void insertAtTail(node *&head, int d){
    if(head == NULL){
        head = new node(d);
        head->next = head;
        return;
    }
    node *tail = head;
    while(tail->next != head){
        tail = tail->next;
    }
    tail->next = new node(d);
    tail->next->next = head;
    return;
}

void insertInMiddle(node *&head, int d, int p){
    if(head == NULL || p == 0){
        insertAtHead(head, d);
        return;
    }
    else if(p > length(head)){
        insertAtTail(head, d);
    }
    else{
        node *temp = head;
        //take p-1 jumps;
        int jump = 1;
        while(jump <= p-1){
            temp = temp->next;
            jump++;
        }
        node *n = new node(d);
        n->next = temp->next;
        temp->next = n;
    }
}

//passing head pointer by value- we do not want to update head value with function
void print(node *head){
    if (head == NULL)
    {
        cout<<"List is empty."<<endl;
        return;
    }
    node *temp = head;
    do{
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    while(temp != head);
    cout<<endl;
}

node* getnode(node *head, int data){
    node *temp = head;
    //for all nodes except last node
    do{
        if(temp->data == data)
            return temp;
        temp = temp->next;
    }
    while(temp != head);
    return NULL;
}

void deletenode(node*&head, int d){
    node* del = getnode(head, d);
    if(del == NULL){
        return;
    }
    if(head == del){
        head = head->next;
    }
    node* temp = head;
    //stop one behind the node to be deleted
    while(temp->next != del){
        temp = temp->next;
    }
    temp->next = del->next;
    delete del;
}

int main(){
    node *head = NULL;
    insertAtHead(head, 4);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    print(head);
    insertInMiddle(head, 3, 3);
    print(head);
    insertAtTail(head, 5);
    print(head);
    deletenode(head, 2);
    print(head);
    deletenode(head, 3);
    print(head);
    deletenode(head, 1);
    print(head);

    // int key;
    // cout<<"Enter element to find: ";
    // cin>>key;
    // if(searchRecusrsive(head, key)){
    //     cout<<"Element Found";
    // }
    // else{
    //     cout<<"Element NOT Found";
    // }

    return 0;   
}