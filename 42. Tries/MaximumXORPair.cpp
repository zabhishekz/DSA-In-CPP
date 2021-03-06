#include<iostream>
using namespace std;
//Find a pair with maximum XOR

class node{
    public:
    node *left;// for 0
    node *right;//for 1
};

class trie{
    node *root;
public:
    trie(){
        root = new node();
    }
    void insert(int n){
        node * temp = root;
        //32 bit integer
        for(int i = 31; i >=0; i--){
            int bit = (n>>i)&1;
            if(bit == 0){
                if(temp->left == NULL){
                    temp->left = new node();
                }
                temp = temp->left;
            }
            else{
                if(temp->right == NULL){
                    temp->right = new node();
                }
                temp = temp->right;
            }
        }
    }
    //helper function to find max xor
    int max_xor_helper(int value){
        int current_ans  = 0;
        node * temp = root;
        for(int j = 31; j >= 0; j--){
            int bit = (value>>j)&1;
            if(bit == 0){
                //find a complementary value
                if(temp->right != NULL){
                    temp = temp->right;
                    current_ans += (1<<j);
                }
                else{
                    temp = temp->left;
                }
            }
            else{
                if(temp->left != NULL){
                    temp = temp->left;
                    current_ans += (1<<j);
                }
                else{
                    temp = temp->right;
                }
            }
        }
        return current_ans;
    }

    int maxXOR(int * input, int n){
        int max_xor = 0 ;
        for(int i = 0; i < n; i++){
            int val = input[i];
            insert(val);
            int current_xor = max_xor_helper(val);
            cout<<"Current XOR: "<<current_xor<<endl;
            max_xor = max(current_xor, max_xor);
        }
        return max_xor;
    }
};



int main(){
    int input[] = {3, 10, 5, 25, 2, 8};
    trie t;
    cout<<"MAximum XOR"<<t.maxXOR(input, 6)<<endl;

    return 0;
}