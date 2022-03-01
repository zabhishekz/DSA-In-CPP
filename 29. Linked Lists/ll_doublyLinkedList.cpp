//Basic operations
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

//passing head pointer by reference- we want to update head value with function
void insertAtHead(node *&head, int d){
    if(head == NULL){
        head = new node(d);
        return;
    }
    node *n = new node(d);
    n->next = head;
    head->prev = n;
    head = n;
}

int length(node *head){
    int cnt = 0;
    while(head != NULL){
        cnt++;
        head = head->next;
    }
    return cnt;
}

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
        n->prev = temp;
        temp->next->prev = n;
        temp->next = n;
    }
}

//passing head pointer by value- we do not want to update head value with function
void print(node *head){
    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}

void deleteAtHead(node *&head){
    if(head == NULL){
        return;
    }
    node *temp = head->next;
    temp->prev = NULL;
    delete head;
    head = temp;
}

void deleteAtTail(node *&head){
    if(head == NULL){
        return;
    }
    node *tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->prev->next = NULL;
    delete tail;
}

void deleteAtMiddle(node *&head, int p){
    if(head == NULL || p == 0){
        return;
    }
    else if(p > length(head)){
        deleteAtTail(head);
    }
    else{
        node *temp = head;
        //take p-1 jumps;
        int jump = 1;
        while(jump <= p-1){
            temp = temp->next;
            jump++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
}

bool search(node *head, int key){
    node *temp = head;
    while(temp!=NULL){
        if(temp->data == key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

//recursive search
bool searchRecusrsive(node *head, int key){
    if(head == NULL){
        return false;
    }
    if(head->data == key){
        return true;
    }
    return searchRecusrsive(head->next, key);
}

int main(){
    node *head = NULL;
    insertAtHead(head, 5);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    print(head);
    insertInMiddle(head, 4, 3);
    print(head);
    insertAtTail(head, 7);
    print(head);
    deleteAtHead(head);
    print(head);
    deleteAtMiddle(head, 3);
    print(head);
    deleteAtTail(head);
    print(head);

    int key;
    cout<<"Enter element to find: ";
    cin>>key;
    if(searchRecusrsive(head, key)){
        cout<<"Element Found";
    }
    else{
        cout<<"Element NOT Found";
    }

    return 0;   
}