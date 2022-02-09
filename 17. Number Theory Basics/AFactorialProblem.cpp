#include<iostream>
#include<vector>
using namespace std;
#define INT_MAX 100000000

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int ans = INT_MAX;
        //Factorization of k
        //p1, p2, p3, ... pl
        int occ = 0;
        for(int i = 2; i*i <= k; i++){
            if(k%i == 0){
                occ = 0;
                while(k%i == 0){
                    occ++;
                    k = k/i;
                }
                //Find out powers of i in n! side by side
                int cnt = 0;
                int p = i;
                while(p <= n){
                    cnt += n/p;
                    p = p*i;
                }
                ans = min(ans, cnt/occ);
            }
        }
        //we may have a case where still a prime factor is left
        if(k > 1){
            int cnt = 0;
            int p = k;
            while(p <= n){
                cnt += n/p;
                p *= k;
            }
            ans = min(ans, cnt);
        }
        if(ans == INT_MAX){
            ans = 0;
        }
        cout<<ans<<endl;
    }
    return 0;
}