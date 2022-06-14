#include<iostream>//standard header files
#include<cstring>
#include"hashtable.h"//userdefined header file
using namespace std;

template<typename T>
class Node{
public:
    string key;
    T value;
    Node<T> *next;
    Node(string key, T val){
        this->key = key;
        value = val;
        next = NULL;
    }
    ~Node(){
        if(next != NULL){
            delete next;
        }
    }
};

template<typename T>
class Hashtable{
    Node<T>** table;//pointer to an array of pointers
    int current_size;
    int table_size;
    int hashfn(string key){
        int idx = 0;
        int p = 1;
        for(int j = 0; j < key.length(); j++){
            idx = idx + (key[j]*p)%table_size;
            idx = idx% table_size;
            p = (p*27)%table_size;
        }
        return idx;
    }
    void rehash(){
        Node<T> ** oldTable = table;
        int oldTableSize = table_size;
        table_size = 2*table_size;//approximation
        table = new Node<T>*[table_size];
        for(int i = 0; i < table_size; i++){
            table[i] = NULL;
        }
        current_size = 0;

        //shift elements from old table to new table
        for(int i = 0; i < oldTableSize; i++){
            Node<T>*temp = oldTable[i];
            while(temp != NULL){
                insert(temp->key, temp->value);
                temp = temp->next;
            }
            if(oldTable[i] != NULL){
                delete oldTable[i];
            }
        }
        delete [] oldTable;
    }
public:
    Hashtable(int ts = 7){
        table_size = ts;
        table = new Node<T>*[table_size];
        current_size = 0;
        for(int i = 0 ; i < table_size; i++){
            table[i] = NULL;
        }
    }
    void insert(string key, T value){
        int idx = hashfn(key);
        Node<T>*n = new Node<T>(key, value);

        //Insert at head of linked list with id = idx
        n->next = table[idx];
        table[idx] = n;
        current_size++;

        //Rehashing
        float load_factor = current_size/(1.0*table_size);
        if(load_factor > 0.7){
            rehash();
        }

    }
    void print(){
        for(int i = 0; i < table_size; i++){
            cout<<"Bucket "<<i<<" ->";
            Node<T>*temp= table[i];
            while(temp != NULL){
                cout<<temp->key<<"->";
                temp = temp->next;
            }
            cout<<endl;
        }
    }
    T* search(string key){
        int idx = hashfn(key);
        Node<T>*temp = table[idx];
        while(temp != NULL){
            if(temp->key==key){ 
                return &temp->value;
            }
            temp = temp->next;
        }
        return NULL;
    } 
    T& operator[](string key){
        T*f = search(key);
        if(f==NULL){
            //Insert key,value pair
            T garbage;
            insert(key, garbage);   
            f = search(key);
        }
        return *f;
    }
};

int main(){
    Hashtable<int> price_menu;
    price_menu.insert("Burger", 120);
    price_menu.insert("Pepsi", 20);
    price_menu.insert("Pizza", 150);
    price_menu.insert("Noodles", 25);
    price_menu.insert("Coke", 40);
    price_menu.print();
    int * price = price_menu.search("Noodles");
    if(price == NULL){
        cout<<"Not found!";
    }
    else{
        cout<<"Price of Noodles is "<<*price<<endl;
    }
    
    //Map
    price_menu["Dosa"] = 60;//insert
    price_menu["Dosa"] += 10;//update
    cout<<"Price of Dosa "<<price_menu["Dosa"]<<endl;//search

    return 0;
}