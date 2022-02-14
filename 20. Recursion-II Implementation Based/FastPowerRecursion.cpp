#include<iostream>
using namespace std;

int FastPower(int a, int n)
{
    if(n == 0)
    {
        return 1;
    }
    int smaller_ans = FastPower(a, n/2);
    smaller_ans *= smaller_ans;
    if(n&1)
    {
        return smaller_ans*a;
    }
    return smaller_ans;
}

int main()
{
    int a, n;
    cin>>a>>n;
    cout<<FastPower(a, n)<<endl;
    return 0;
}