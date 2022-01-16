#include<iostream>
using namespace std;

int main(){
    int n, i, a[100];
    int cumsum[100] = {0};
    int maxsum = 0;
    int cursum = 0;
    int left = -1;
    int right = -1;
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements:\n";
    cin>>a[0];
    cumsum[0] = a[0];
    for(int i = 1; i < n; i++){
        cin>>a[i];
        cumsum[i] = cumsum[i-1] + a[i];    //precomputing
    }
    
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            cursum = 0;
            cursum = (i-1)>=0 ? cumsum[j]-cumsum[i-1] : cumsum[j]; 
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