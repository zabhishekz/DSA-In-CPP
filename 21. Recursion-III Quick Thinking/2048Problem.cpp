#include<iostream>
using namespace std;

char words[][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void Problem(int num)
{
    if(num == 0)
    {
        return;
    }
    Problem(num/10);
    int dig = num%10;
    cout<<words[dig]<<" ";
    return;
}

int main()
{
    int number;
    cin>>number;
    Problem(number);
    return 0;
}