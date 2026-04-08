#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define int long long

int binexp(int a, int b, int mod = -1)
{
    if(b == 0)
    return 1;

    if(b % 2)
    {
        int res = a * binexp(a, b - 1, mod);
        return (mod == -1) ? res : res % mod;
    }
    else
    {
        int tmp = binexp(a, b/2, mod);
        int res = tmp * tmp;
        return (mod == -1) ? res : res % mod;
    }
}

bool check(int x, int n, int m)
{
    // if(binexp(x, n) <= m)
    // {
    //     return 1;
    // }
    // else
    // {
    //     return 0;
    // } We dont need binexp here. We can do early stop

    int res = 1;
    for(int i = 0; i < n; i++)
    {
        res *= x;

        if(res > m)
        {
            return 0;
        }
    }
    return 1; //This gives TC : nlogm

    //ToDo: Find a more optimal solution using a modified binexp
}

void solve()
{
    int n, m;
    cin>>n>>m;

    int lo = 1;
    int hi = m;
    int ans = -1;

    while(lo <= hi)
    {   int mid = lo + (hi - lo) / 2;

        if(check(mid, n, m))
        {
            ans = mid;
            lo = mid + 1;
        }
        else 
        {
            hi = mid - 1;
        }

    }

    if(ans != -1 && binexp(ans, n) == m)
    {
        cout<<ans<<"\n";
    }
    else
    {
        cout<<"Not found\n";
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