#include<iostream>
#include<algorithm>
using namespace std;

bool CanPlaceCows(int stalls[], int n, int c, int minsep)
{
    int lastcow = stalls[0];
    int cnt = 1;
    for(int i = 1; i < n; i++)
    {
        if(stalls[i] - lastcow >= minsep)
        {
            lastcow = stalls[i];
            cnt++;
            if(cnt == c)
                return true;
        }
    }
    return false;
}

int main()
{
    int stalls[100000];
    int n, c;
    cin>>n>>c;
    for(int i = 0; i < n; i++)
    {
        cin>>stalls[i];
    }
    sort(stalls, stalls+n);
    int s = 0;
    int e = stalls[n-1] - stalls[0];
    int ans = 0;

    while(s <= e)
    {
        int mid = (s+e)>>1;
        bool CowsRakhPaye = CanPlaceCows(stalls, n, c, mid);
        if(CowsRakhPaye == 1)
        {
            ans = mid;
            s = mid+1;
        }
        else
        {
            e = mid-1;
        }
    }
    cout<<ans<<endl;

    return 0;
}