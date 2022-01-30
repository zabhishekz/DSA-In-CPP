#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int arr[] = {20, 30, 40, 40, 40, 50, 100, 1100};
    int n = sizeof(arr)/sizeof(int);
    int key;
    cin>>key;

    bool present = binary_search(arr, arr+n, key); 
    if(present)
        cout<<"Present";
    else
        cout<<"Not Present";

    auto lb = lower_bound(arr, arr+n, key);
    cout<<endl<<"Lower bound of "<<key<<" is "<<(lb-arr);
    auto ub = upper_bound(arr, arr+n, key);
    cout<<endl<<"Upper bound of "<<key<<" is "<<(ub-arr);

    cout<<endl<<"Occurrences of "<<key<<" is "<<(ub-lb);

    return 0;    

}