#include<iostream>
using namespace std;

void generatesubsequences(char *in, char * out, int i, int j)
{
    //base case
    if(in[i] == '\0')
    {
        out[j] = '\0';
        cout<<"->"<<out<<endl;
        return;
    }
    //rec case
    //include the current character
    out[j] = in[i];
    generatesubsequences(in, out, i+1, j+1);
    //exclude the current character
    generatesubsequences(in, out, i+1, j);
}

int main()
{
    char inp[1000];
    char out[1000];
    cin>>inp;
    generatesubsequences(inp, out, 0, 0);
    return 0;
}