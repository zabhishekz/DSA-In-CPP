#include<iostream>
using namespace std;

int RecursiveBinarySearch(int arr[], int s, int e, int key)
{
    if(s <= e)
    {
        int mid = (s + e)/2;
        if(key == arr[mid])
        {
            return mid;
        }
        else if(arr[mid] > key)
        {
            return RecursiveBinarySearch(arr, s, mid -1, key);
        }
        else
        {
            return RecursiveBinarySearch(arr, mid +1 , e, key);
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key;
    cin>>key;
    int n = sizeof(arr)/sizeof(int); 
    int result = RecursiveBinarySearch(arr, 0, n - 1, key); 
    (result == -1) ? cout << "Element is not present in array" : cout << "Element is present at index " << result; 
    return 0;
}