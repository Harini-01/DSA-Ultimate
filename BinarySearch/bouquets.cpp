/*
1482. Minimum Number of Days to Make m Bouquets
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

 

Example 1:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
Example 2:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
Output: -1
Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 flowers. We only have 5 flowers so it is impossible to get the needed bouquets and we return -1.
Example 3:

Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
Output: 12
Explanation: We need 2 bouquets each should have 3 flowers.
Here is the garden after the 7 and 12 days:
After day 7: [x, x, x, x, _, x, x]
We can make one bouquet of the first three flowers that bloomed. We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
After day 12: [x, x, x, x, x, x, x]
It is obvious that we can make two bouquets in different ways.
 

Constraints:

bloomDay.length == n
1 <= n <= 105
1 <= bloomDay[i] <= 109
1 <= m <= 106
1 <= k <= n*/

class Solution {
public:

    bool check(vector<int>& bloomDay, int m, int k, int d)
    {
        int bouquets = 0;
        int adjflowers = 0;
        for(auto i:bloomDay)
        {
            if(i <= d)
            {
                adjflowers++;
                if(adjflowers == k)
                {
                    bouquets++;
                    adjflowers = 0;
                }

                if(bouquets >= m)
                {
                    return 1;
                }
            }
            else
            {
                adjflowers = 0;
            }
        }

        return 0;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int lo = 1, hi = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while(lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            if(check(bloomDay, m, k, mid))
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
n = size of bloomDay array

Binary Search:
- Search space: [min(bloomDay), max(bloomDay)]
- Number of iterations = O(log₂(max(bloomDay)))

Check Function:
- For each day (mid), we traverse the entire array once
- Time = O(n)

Total Time Complexity:
= O(n * log(max(bloomDay)))

--------------------------------------------------

Constraint-based Estimation:

Given:
n ≤ 10^5
bloomDay[i] ≤ 10^9

log₂(10^9) ≈ 30

Total operations:
≈ n * log(max)
≈ 10^5 * 30
≈ 3 * 10^6 operations

This is well within limits (<< 10^8), so it will run efficiently.

--------------------------------------------------

Space Complexity:
O(1)
(No extra space used apart from variables)

--------------------------------------------------

Key Insight:
- This is a Binary Search on Answer problem
- We search for the minimum day such that we can form at least m bouquets
- Check function ensures adjacency constraint (k consecutive flowers)
*/