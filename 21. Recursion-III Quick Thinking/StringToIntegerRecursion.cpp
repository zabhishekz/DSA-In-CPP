#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;

int stringToInt(char *a, int n)
{
    if(n == 0)
    {
        return 0;
    }
    int dig = a[n-1] - '0';
    int small_ans = stringToInt(a, n-1);
    return small_ans*10 + dig;
}

int main()
{
    char a[] = "1234 ";
    int len = strlen(a);
    cout<<stringToInt(a, len);
    return 0;
}


// int stringToInt(char *a, int i, int n)
// {
//     if(n == 0)
//     {
//         return 1;
//     }
//     int dig = a[i] - '0';
//     int small_ans = (dig*pow(10, n-1));
//     return small_ans+stringToInt(a, i+1, n-1);
// }

// int main()
// {
//     char a[] = "9130";
//     int len = strlen(a);
//     cout<<stringToInt(a, 0, len);
//     return 0;
// }