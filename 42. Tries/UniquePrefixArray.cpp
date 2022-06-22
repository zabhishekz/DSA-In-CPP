#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
public:
    char data;
    unordered_map<char, Node*> children;
    int freq;
    bool terminal;
    Node(char d){
        data = d;
        terminal = false;
        freq = 0;
    }
};

class Trie{
    Node*root;
public:
    Trie(){
        root = new Node('\0');
    }
    void insert(char *w){
        Node *temp = root;
        for(int i = 0; w[i] != '\0'; i++){
            char ch = w[i];
            if(temp->children.count(ch)){
                temp = temp->children[ch];
                temp->freq = temp->freq + 1;
            }
            else{
                Node *n = new Node(ch);
                temp->children[ch] = n;
                temp = n;
                temp->freq = temp->freq + 1;
            }
        }
        temp->terminal = true;
    }
    bool find(char *w){
        Node *temp = root;
        for(int i = 0; w[i] != '\0'; i++){
            char ch = w[i];
            if(temp->children.count(ch) == 0){
                return false;
            }
            else{
                temp = temp->children[ch];
            }
        }
        return temp->terminal;
    }
    string printUniquePrefix(string x){
        int i = 0;
        int len = x.length();
        string ans = "";
        Node *temp = root;
        while(i != len){
            if((temp->children[x[i]])->freq == 1){
                ans = ans + x[i];
                return ans;
            }
            else{
                ans = ans + x[i];
                temp = temp->children[x[i]];
            }
            i++;
        }
        ans = "-1";
        return ans;
    }
};

int main(){
    
    Trie t;
    char words[][10] = {"cobra", "dog", "dove", "duck", "cobras"};
    for(int i = 0; i < 5; i++){
        t.insert(words[i]);
    }
    for(int i = 0; i < 5; i++){
        cout<<t.printUniquePrefix(words[i])<<", ";
    }
    return 0;
}