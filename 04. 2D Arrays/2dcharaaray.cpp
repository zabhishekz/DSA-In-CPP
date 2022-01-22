#include<iostream>
using namespace std;

int main()
{
    char a[][10] = {{'a','b','\0'}, {'d', 'e', 'f', '\0'}};
    cout<<a[0]<<endl;
    cout<<a[1]<<endl;

    char b[][10] = {"abc","def","ghi","hello"};
    cout<<b[2]<<endl;
    cout<<b[3]<<endl;

    b[0][0] = 'X';
    cout<<b[0]<<endl;

    return 0;
}