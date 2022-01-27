#include<iostream>
using namespace std;

int main()
{
    int x = 10;
    cout<<&x<<endl;
    
    char ch = 'A';
    cout<<&ch;
    cout<<(void *)&ch<<endl;

    cout<<"SinglePointers-----"<<endl;
    x = 10;
    int *xptr;
    xptr = &x;

    cout<<&x<<endl;         //address of x variable
    cout<<xptr<<endl;       //value in xptr i.e, address of x variable
    cout<<*(&x)<<endl;      //value stored at address x
    cout<<*(xptr)<<endl;    //dereferncing xptr
    cout<<*(&xptr)<<endl;   
    cout<<&(*xptr)<<endl;
    cout<<"DoublePointers-----"<<endl;
    cout<<&xptr<<endl;
    int **xxptr = &xptr;
    cout<<xxptr<<endl;

    return 0;
}