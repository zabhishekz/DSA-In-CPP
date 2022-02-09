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

int no_of_divisors(int m, vector<int> &primes){   
    int i = 0;
    int p = primes[0];
    int ans = 1;
    while(p*p <= m){
        if(m % p == 0){
            int cnt = 0;
            while(m%p == 0){
                cnt++;
                m = m/p;
            }
            ans = ans*(cnt+1);
        }

        //go to next position
        i++;
        p = primes[i];
    }
    if(m != 1){
        ans = ans*2;
    }
    return ans;
    
}

int main(){
    int N = 1000000;
    int p[N] = {0};
    vector<int> primes= primeSieve(p, 10000);

    int t;
    cin>>t;
    while(t--){
        int no;
        cin>>no;
        int divs = no_of_divisors(no, primes);
        cout<<divs<<endl;
    } 
    return 0;
}