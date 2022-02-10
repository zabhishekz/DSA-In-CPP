#include<iostream>
using namespace std;

void Inc(int n)
{
    //Base Case
    if(n == 0)
    {
        return;
    }
    //Recursive Case
    Inc(n-1);
    cout<<n<<" ";

}

void Dec(int n)
{
    //Base Case
    if(n == 0)
    {
        return;
    }
    //Recursive Case
    cout<<n<<" ";
    Dec(n-1);
}

int main()
{
    int n;
    cin>>n;
    Inc(n);
    cout<<endl;
    Dec(n);
    return 0;
}