#include<iostream>
using namespace std;

// void bubblesort(int a[], int n)
// {
//     for(int i = 0; i < n-1; i++)
//     {
//         for(int j = 0; j<n-i-1; j++)
//         {
//             if(a[j]>a[j+1])
//             {
//                 swap(a[j], a[j+1]);
//             }
//         }
//     }
// }

void bubble_sort(int a[], int n)
{
    if(n == 1)
    {
        return;
    }
    for(int j = 0; j < n-1; j++)
    {
        if(a[j] > a[j+1])
        {
            swap(a[j], a[j+1]);
        }
    }
    bubble_sort(a, n-1);
}
//Use either functions

void bubble_sort_recursive(int a[], int j, int n)
{
    if(n == 1)
    {
        return;
    }
    if(j == n-1)
    {
        return bubble_sort_recursive(a, 0, n-1);;
    }
    if(a[j] > a[j+1])
    {
        swap(a[j], a[j+1]);
    }
    bubble_sort_recursive(a, j+1, n);
    return;
}

int main()
{
    int arr[] = {1, 4, 5, 2, 3};
    int n = 5;
    bubble_sort_recursive(arr, 0, n);
    for(int  i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}