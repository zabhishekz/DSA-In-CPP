#include<iostream>
#include<climits>
using namespace std;

int main(){
    int a[100];
    int i, n;
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin>>a[i];

    int smallest = INT_MAX;
    int largest = INT_MIN;
    for(int i = 0; i < n; i++){
        if(a[i] < smallest)
            smallest = a[i];  //other way using inbuilt functions: smallest = min(smallest,a[i])
        if(a[i] > largest)
            largest = a[i];   //largest = max(largest,a[i])
    }
    cout<<"Smallest number is "<<smallest<<endl;
    cout<<"Largest number is "<<largest;
    
    return 0;
}