#include<iostream>
using namespace std;

void allOcc(int *a, int i, int n, int key)
{
    if(i == n)
    {
        return;
    }
    if(a[i] == key)
    {
        cout<<i<<", ";
    }
    allOcc(a, i+1, n, key);
}

int storeOccurences(int *a, int i, int n, int key, int *out, int j)
{
    if(i == n)
    {
        return j;
    }
    if(a[i] == key)
    {
        out[j] = i;
        return storeOccurences(a, i+1, n, key, out, j+1);
    }
    return storeOccurences(a, i+1, n, key, out, j);
}

int main()
{
    int arr[] = {1, 2, 3, 7, 4, 5, 6, 7, 8};
    int key = 7;
    int n = sizeof(arr)/sizeof(int);
    allOcc(arr, 0, n, key);
    cout<<endl;
    int output[100];
    int cnt =  storeOccurences(arr, 0, n, key, output, 0);
    for(int k = 0; k < cnt; k++)
    {
        cout<<output[k]<<" "; 
    }
    return 0;
}