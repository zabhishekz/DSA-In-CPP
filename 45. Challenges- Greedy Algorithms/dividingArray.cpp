#include<iostream>
using namespace std;
#define ll long long
int main() {
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v1;
		for(int i=0 ; i<n ; i++){
			ll a;
			cin>>a;
			v1.push_back(a);
		}
        sort(v1.begin(),v1.end());
        ll mn = 0, mx = 0;
        for(int i = 0; i < n; i+=2){
            mn += v1[i+1]-v1[i];
        }
        for(int i=0;i<n/2;i++){
            mx += v1[n-i-1]-v1[i];
        }
        cout<<mn<<" "<<mx<<'\n';
	}
	return 0;
}