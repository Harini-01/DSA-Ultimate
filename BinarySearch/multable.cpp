#include<iostream>
#include<bits/stdc++.h>
#define int long long

using namespace std;

int check(int mid, int n, int m, int k)
{
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        cnt += min(mid / i, m);
    }

    if(cnt >= k) return 1;
    else return 0;
}


void solve()
{
    int n, m, k;
    cin>>n>>m>>k;

    int lo = 0;
    int hi = n * m;
    int ans = -1;

    while(lo <= hi)
    {
        int mid = lo + (hi - lo)/2;

        if(check(mid, n, m, k) == 1)
        {
            hi = mid - 1;
            ans = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }

    cout<<ans<<"\n";
}

signed main()
{
    int t = 1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
}