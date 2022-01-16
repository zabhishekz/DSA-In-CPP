#include<iostream>
using namespace std;

int main(){
    int n, i, a[100];
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin>>a[i];
    
    int maxsum = 0;
    int cursum = 0;
    int left = -1;
    int right = -1;

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            cursum = 0;
            for(int k = i; k <= j; k++){
                cursum += a[k]; 
            }
            if(cursum > maxsum){
                maxsum = cursum;
                left = i;
                right = j;
            }
        }
    }

    cout<<"Maximum sum is "<<maxsum<<endl;
    for(int k = left; k <= right; k++)
        cout<<a[k]<<", ";
    return 0;
}