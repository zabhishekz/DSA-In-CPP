#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    int t, n, q;
    cin>>t;
    while(t != 0){
        cin>>n;
        unordered_map<int, bool> hm;
        for(int i = 0; i < n; i++){
            int no;
            cin>>no;
            hm[no] = true;     
        }
        cin>>q;
        while( q != 0){
            int num;
            cin>>num;
            if(hm[num] == true){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
            q--;
        }
        t--;
    }

    return 0;
}