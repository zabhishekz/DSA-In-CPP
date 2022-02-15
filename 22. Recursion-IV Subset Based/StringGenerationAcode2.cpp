#include<iostream>
#include<string>
using namespace std;

void generate(string inp, string out, int idx, int n){
    if(idx == n){
        cout<<out<<endl;
        return;
    }
    int dig = inp[idx]-'0';
    char c = dig + 'A' - 1;
    if(idx+1 == n){
        generate(inp,out+c,idx+1,n);
    }
    else{
        generate(inp,out+c,idx+1,n);
        int dig2 = inp[idx+1] - '0';
        int num = dig*10 + dig2;
        if(num <= 26){   
            char c2 = num + 'A' - 1;    
            generate(inp,out+c2,idx+2,n);
        }
    }
}

int main(){
    string inp = "1234";
    string out = "";
    int n = inp.length();
    generate(inp,out,0,n);
    return 0;
}