#include<iostream>
#include<bits/stdc++.h>
#define int long long

using namespace std;

int check(int mid, int n,int m, int arr[], int brr[])
{
    int lastTowerCover = -1e18;
    int towerPlanted = 0;

    for(int i = 0; i < n; i++)
    {
        if(lastTowerCover >= arr[i])
        {
            continue;
        }

        int lo = arr[i] - mid;
        int hi = arr[i] + mid;

        int *itr = upper_bound(brr, brr + m, hi);
        if(itr == brr)
        {
            return 0;
        }
        else
        {
            itr--;
            if(lo <= *itr)
            {
                towerPlanted++;
                lastTowerCover = (*itr) + mid;
            }
            else{
                return 0;
            }
        }

        
    }

    // if(towerPlanted > k) return 0;
        // else
        return 1;

    
}


void solve()
{
    int n, m;
    cin>>n>>m;

    int arr[n];
    int brr[m];

    for(int i = 0; i < n; i++) cin>>arr[i];
    for(int j = 0; j < m; j++) cin>>brr[j];

    int lo = 0;
    int hi = 2e9;
    int ans = -1;

    while(lo <= hi)
    {   
        int mid = lo + (hi - lo) / 2;
        if(check(mid, n, m, arr, brr) == 1)
        {
            ans = mid;
            hi = mid - 1;
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