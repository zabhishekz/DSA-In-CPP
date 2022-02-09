#include<iostream>
#include<vector>
using namespace std;  

void printfactors(int n){
    vector<pair<int, int>> factors;
    int cnt;
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0){
            cnt = 0;
            //keep on dividign till it is divisibe
            while(n %i == 0){
                cnt++;
                n = n/i; 
            }
            factors.push_back(make_pair(i, cnt));
        }
    }
    if( n != 1){
        //whatever is left is a prime number itself
        factors.push_back(make_pair(n, 1));
    }
    //print the factors
    for(auto p: factors){
        cout<<p.first<<"^"<<p.second<<endl;
    }
    return ;
}

int main(){
    int n;
    cin>>n;
    printfactors(n);
}