#include<iostream>
using namespace std;
#define ll long long

void prime_sieve(int *p){
    //first mark all odd numbers as prime
    for(int i = 3; i <= 1000000; i += 2){
        p[i] = 1;
    }
    //sieve
    for(ll i = 3; i <= 1000000; i += 2){
        // if the current number is not marked(It is prime)
        if(p[i] == 1){
            //mark all the multiples of i as not prime
            for(ll j = i*i; j <= 1000000; j += i){
                p[j] = 0;
            }
        }
    } 
    //special cases
    p[2] = 1;
    p[1] = p[0] = 0;
}

int main(){
    int p[1000005] = {0};
    prime_sieve(p);
    int cumsum[1000005] = {0};
    //precompute the primes upto an index i
    for(int i = 1; i <= 1000000; i++){
        cumsum[i] = cumsum[i-1] + p[i];
    }

    int q;
    cin>>q;
    while(q--){
        int a, b;
        cin>>a>>b;
        cout<<cumsum[b]-cumsum[a-1]<<endl;
    }
    return 0;
}