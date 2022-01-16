#include<iostream>
using namespace std;

int main(){
    char a[]={'a', 'b', 'c','\0'};
    char b[]={'a', 'b', 'c'};
    cout<<a<<endl;
    cout<<sizeof(a)<<endl;
    cout<<b<<endl;
    cout<<sizeof(b)<<endl;

    char c[4]={'a', 'b', 'c','\0'};
    cout<<c<<endl;
    cout<<sizeof(c)<<endl;

    char d[]="def";
    cout<<d<<endl;
    cout<<sizeof(d)<<endl;

    char f[10];
    cin>>f;
    cout<<f;

    return 0;
}