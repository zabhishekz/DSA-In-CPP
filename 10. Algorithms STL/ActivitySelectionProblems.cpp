#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(pair <int, int> a, pair <int, int> b)
{
    return a.second < b.second;
}

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int n, a, b;
        cin>>n;
        pair <int, int> arr[10000];
        for(int i = 0; i < n; i++)
        {
            cin>>a>>b;
            arr[i] = make_pair(a, b);
        }
        sort(arr, arr+n, cmp);
        int ans = 1;
        int chosen = 0;
        for(int i = 1; i < n; i++)
        {
            if(arr[i].first >= arr[chosen].second)
            {
                ans++;
                chosen = i;
            }
        }
        cout<<ans<<endl;
        t--;
    }

    return 0;
}