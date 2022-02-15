#include<iostream>
using namespace std;

string keypad[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void generate_name(string inp, string out, int idx, int n){
    if(idx == n){
        cout<<out<<endl;
        return;
    }
    int dig = inp[idx]-'0';
    if(dig == 0 or dig == 1){
        generate_name(inp,out,idx+1,n);
    }
    for(int i = 0; i < keypad[dig].length(); i++){
        generate_name(inp,out+keypad[dig][i],idx+1,n);
    }
    return;
}

int main(){
    string inp = "666";
    int n = inp.length();
    string out = "";
    generate_name(inp,out,0,n);
    return 0;
}