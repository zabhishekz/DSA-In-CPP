#include<iostream>
#include<bitset>
#include<vector>
using namespace std;
const int n = 10000000;
bitset<10000005> b;
vector <int> primes;

void sieve(){
    b.set();
    b[0] = b[1] = 0;

    for(long long int i = 2; i <= n; i++){
        if(b[i]){
            primes.push_back(i);
            for(long long int j = i*i; j <= n; j++){
                b[j] = 0;
            }
        }
    }
}

bool isPrime(long long int No){
    if( No <= n){
        return b[No] == 1 ? true : false;
    }
    for(long long int i = 0; primes[i]*(long long)primes[i] <= No; i++){
        if(No%primes[i] == 0){
            return false;
        }
    }
    return true;
}

int main(){   
    sieve();
    if(isPrime(2147483647)){
        cout<<"Yes it's Prime!";
    }
    else{
        cout<<"Not Prime!";
    }
    return 0;
}