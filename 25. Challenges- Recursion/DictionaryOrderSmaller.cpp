#include<iostream>
#include<set>
#include<string>
using namespace std;

void permute(string in, string oin, int i,  set <string> &s)
{
    if(in[i] == '\0')
    {
        if(in<oin){
            string t(in);
            s.insert(t);
        }
        return;
    }
    for(int j = i; in[j] != '\0'; j++)
    {
        swap(in[i], in[j]);
        permute(in, oin, i+1, s);
        swap(in[i], in[j]);
    }
}

int main()
{
    string in;
    cin>>in; 
    string oin = in;
    set <string> s;
    permute(in, oin, 0, s);
    for(auto str: s)
    {
        cout<<str<<endl;
    }
    return 0;
}