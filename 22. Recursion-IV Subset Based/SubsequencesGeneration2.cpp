#include<iostream>
using namespace std;

void generste_subs(string inp, string out, int idx, int n){
    if(idx == n){
        cout<<out<<endl;
        return;
    }
    generste_subs(inp,out+inp[idx],idx+1,n);
    generste_subs(inp,out,idx+1,n);
}

int main(){
    string inp = "abc";
    string out = "";
    int n = inp.length();
    generste_subs(inp,out,0,n);
    return 0;
}