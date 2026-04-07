#include<iostream>
#include<bits/stdc++.h>
#define int long long

using namespace std;

int check(int mid, int arr[], int n, int t)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += mid / arr[i];
    }

    if(sum >= t)
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
    int n, t;
    cin>>n>>t;

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int lo = 0;
    int hi = t * *min_element(arr, arr + n);
    int ans = -1;

    while(lo <= hi)
    {
        int mid = lo + (hi - lo)/2;

        if(check(mid, arr, n, t) == 1)
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
