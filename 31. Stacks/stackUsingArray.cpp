#include<iostream>
using namespace std;
#define maxsize 5
int stack[maxsize];
int top=-1;

void push()
{
    if(top == maxsize-1)
    {
        cout<<"Overflow!!!";
    }
    else
    {
        cout<<"Enter value to be added in stack: ";
        int val;
        cin>>val;

        top=top+1;
        stack[top]=val;
    }
}

void pop()
{
    if(top==-1)
    {
        cout<<"Underflow!!!";
    }
    else
    {
        top--;
    }
}

void display()
{
    if(top==-1)
    {
        cout<<"The stack is empty.";
    }
    else
    {
        printf("Stack:\n");
        for(int i=top;i>=0;i--)
        {
            cout<<"Stack["<<i<<"] "<<stack[i]<<endl;;
        }
    }
}

void peek()
{
    if(top==-1)
    {
        cout<<"The stack is empty.";
    }
    else
    {
        cout<<"top points to element:"<<stack[top];
    }
}
int main()
{
    char ch;
    int select;
    cout<<"Do you want to perform operations on Stack?(y/n): ";
    cin>>ch;
    while(ch!='n')
    {
        cout<<"\nEnter choice for operation:\n1.Push\n2.Pop\n3.Display\n4.Peek\n";
        cin>>select;
        switch(select)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: peek();
                    break;
            default: cout<<"Choose a valid operation from the list.";
        }
        cout<<"\nDo you want to perform operations on Stack?(y/n): ";
        cin>>ch;
    }
    return 0;
}
