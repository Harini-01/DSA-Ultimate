#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define int long long

int check(int x, int n)
{
    if ( x * x <= n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void solve()
{
    int n;
    cin>>n;

    int lo = 1;
    int hi = n;
    int ans = -1;

    while ( lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (check(mid, n))
        {
            lo = mid + 1;
            ans = mid;
        }
        else
        {
            hi = mid - 1;
        }
    }

    if(ans != -1)
    {
        cout<<ans<<"\n";
    }
    else
    {
        cout<<"Couldnt find ans\n";
    }
}

signed main()
{
    int t;
    cin>>t;

    while(t--)
    {
        solve();
    }
}