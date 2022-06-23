#include<iostream>
#include<map>
using namespace std;

int main(){
    string s, t;
    getline(cin, s);
    getline(cin, t);
    int n = s.size();
    int m = t.size();
    int l = 0;
    int r;

    map<char, int> ms, mt;
    int resl = -1;
    int resr = 1e9;

    for(auto x: t){
        mt[x]++;
    }

    for(r = 0; r < n; r++){
        //check if string from l to r is a good string
        ms[s[r]]++;
        bool good = true;
        for(auto x: mt){
            //x is {char, int}
            if(ms.count(x.first)==0 || ms[x.first] < x.second){
                good = false;
                break;
            }
        }
        //if string from l to r is a NOT good
        if(!good){
            continue;
        }
        //otherwise it is a good window
        //move l forward for every r
        while(l < n and l <= r and mt.count(s[l])==0 || ms[s[l]] > mt[s[l]]){
            ms[s[l]]--;
            if(ms[s[l]] == 0){
                ms.erase(s[l]);
            }
            l++;
        }
        if(resr-resl+1 > r-l+1){
            resl = l;
            resr = r;
        }
    }

    if(resl == -1){
        cout<<"No String";
    }
    else{
        cout<<s.substr(resl, resr-resl+1);
    }
    return 0;
}