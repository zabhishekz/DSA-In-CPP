#include<iostream>
#include<vector>
using namespace std;

//Prime sieve optimization
vector<int> primeSieve(int *p, int n){
    p[2] = 1;
    p[1] = p[0] = 0;

    for(int i = 3; i <= n; i += 2){
        p[i] = 1;
    }

    //Sieve login to mark non prime numbers as 0
    //1.Optimization-iterate over odd numbers only
    for(int i = 3; i <= n; i += 2){
        // if the current number is not marked(It is prime)
        if(p[i] == 1){
            //mark all the multiples of i as not prime
            //2.Optimization-take a jump if 2i starting from i*i
            for(int j = i*i; j <= n; j += 2*i){
                p[j] = 0;
            }
        }
    } 
    vector<int> primes;
    primes.push_back(2);
    for(int i = 3; i <= n; i+=2){
        if(p[i] == 1){
            primes.push_back(i);
        }
    }
    return primes;
}

//This returns a vector of prime numbers
vector<int> factorize(int m, vector<int> &primes){  
    vector<int> factors;
    factors.clear();
    int i = 0;
    int p = primes[0];
    while(p*p <= m){
        if(m % p == 0){
            factors.push_back(p);
            while(m%p == 0){
                m = m/p;
            }
        }

        //go to next position
        i++;
        p = primes[i];
    }
    if(m != 1){
        factors.push_back(m);
    }
    return factors;
    
}

int main(){
    int N = 1000000;
    int p[N] = {0};
    vector<int> primes= primeSieve(p, 100);
    int t;
    cin>>t;
    while(t--){
        int no;
        cin>>no;
        vector<int> factors = factorize(no, primes);
        for(auto f: factors){
            cout<<f<<" "<<endl;
        }
    } 
    return 0;
}