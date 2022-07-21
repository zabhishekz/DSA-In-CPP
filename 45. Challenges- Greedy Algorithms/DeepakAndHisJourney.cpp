#include <iostream>
using namespace std;
int main() {
    long long int t;
    cin>>t;
    while(t--)
    {
       long long int n;
        cin>>n;
        long long int cost[n];
        long long int petrol[n];
        for(int i=0;i<n;i++){
            cin>>cost[i];
        }
        for(int i=0;i<n;i++){
            cin>>petrol[i];
        }
        long long int min_cost = cost[0];
        long long int total = min_cost*petrol[0];
        for(int i = 1; i < n; i++){
            if(min_cost > cost[i]){
                min_cost=cost[i];
                total=total+min_cost*petrol[i];
                continue;
            }
            else{
                total=total+min_cost*petrol[i];
                continue;
            }
        }
        cout<<total<<endl;
    }
}