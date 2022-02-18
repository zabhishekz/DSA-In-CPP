#include<iostream>
#include<cstring>
using namespace std;

void moveatend(char inp[],int i, int l){
    if( i == l){
        return;
    }
    if(inp[i] != 'x'){
        cout<<inp[i];
    }
    moveatend(inp,i+1,l);
    if(inp[i] == 'x'){
        cout<<'x';
    }
}

int main() {
    char inp[10001];
    cin>>inp;
    int l = strlen(inp);
    moveatend(inp,0,l);
}
