#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std;

void bubble_sort(int a[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0;j < (n-i-1); j++)
        {
            if(a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
            } 
        }
    }
}

int main()
{
    int n, i, a[10000];
    cout<<"Enter number of elements: ";
    cin>>n;
    for(int i = 0; i < n; i++)
        a[i] = n-i;
        
    time_t start = clock();
    bubble_sort(a, n);
    time_t end = clock();
    cout<<"Bubble Sort"<<end-start<<endl;
    
    start = clock();
    sort(a, a+n);
    end = clock();
    cout<<"Inbuilt Sort"<<end-start<<endl;
    return 0;

}
