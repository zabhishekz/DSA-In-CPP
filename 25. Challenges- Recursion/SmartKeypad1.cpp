#include<iostream>
#include<string>
using namespace std;

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void generate_names(char *in, char *out, int i, int j)
{
    if(in[i] == '\0')
    {
        out[j] = '\0';
        cout<<out<<endl;
        return;
    }
    int dig = in[i]-'0';
    if(dig == '0')
    {
        generate_names(in, out, i+1, j);
    } 
    for(int k = 0; table[dig][k] != '\0'; k++)
    {
        out[j] = table[dig][k];
        generate_names(in, out, i+1, j+1);
    }
    return;
}

int main()
{
    char in[10], out[10];
    cin>>in;
    generate_names(in, out, 0, 0);
    return 0;
}