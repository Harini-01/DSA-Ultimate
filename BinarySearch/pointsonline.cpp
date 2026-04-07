#include<iostream>
#include<bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
    int n, d;
    cin>>n>>d;

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int ans = 0;

    for(int i = 0; i < n - 2; i++)
    {
        int a = arr[i];
        int lim = a + d;
        int extra = (upper_bound(arr+i+1, arr+n, lim) - (arr+i+1));
        //cout<<a<<"\t"<<lim<<"\t"<<extra<<"\n";
        ans += ((extra * (extra - 1)) / 2);
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