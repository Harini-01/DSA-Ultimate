/*Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23*/

class Solution {
public:

    int ceil(int a, int b)
    {
        return (a + b - 1) / b;
    }

    bool check(vector<int>&piles, int h, int x)
    {
        int timetaken = 0;
        for(auto i:piles)
        {
            timetaken += ceil(i, x);
            if(timetaken > h)
            {
                return 0;
            }
        }
        return 1;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
       int lo = 1, hi = *max_element(piles.begin(), piles.end());
        int ans = -1;

       while(lo <= hi)
       {
        int mid = lo + (hi - lo) / 2;
        if(check(piles, h, mid) == 1)
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }

       }

       return ans;
    }
};

/*
Time Complexity Analysis:

Let:
n = number of piles
max_ele = maximum value in piles[]

Binary Search:
- Search space: [1, max_ele]
- Number of iterations = O(log₂(max_ele))

Check Function:
- For each mid (speed), we iterate over all piles
- Time = O(n)

Total Time Complexity:
= O(n * log(max_ele))

--------------------------------------------------

Constraint-based Estimation:

Given:
n ≤ 10^4
max_ele ≤ 10^9

log₂(10^9) ≈ 30

Total operations:
≈ n * log(max_ele)
≈ 10^4 * 30
≈ 3 * 10^5 operations per test case

Even with multiple test cases, this is well within limits
(<< 10^8), so it will run efficiently.

--------------------------------------------------

Space Complexity:
O(1) (no extra space used apart from variables)
*/