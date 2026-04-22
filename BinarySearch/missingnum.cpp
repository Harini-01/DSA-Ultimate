/*1539. Kth Missing Positive Number
Solved
Easy
Topics
premium lock icon
Companies
Hint
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.

 

Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
 

Constraints:

1 <= arr.length <= 1000
1 <= arr[i] <= 1000
1 <= k <= 1000
arr[i] < arr[j] for 1 <= i < j <= arr.length
 */

 class Solution {
public:
    bool check(int x, vector<int>& arr, int k)
    {
        // auto it = upper_bound(arr.begin(), arr.end(), x);
        // int bound = *(--it);
        // if(bound == x)
        // {
        //     return 0;
        // }
        // int index = distance(arr.begin(), it); 
        
        // int nums = (x - bound) + (index);

        // return nums >= k;


        int count = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
        int missing = x - count;

        return missing >= k;
    }

    int findKthPositive(vector<int>& arr, int k) {
        int lo = 1;
        int hi = arr.back() + k;
        int ans = -1;

        while(lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            

            if(check(mid, arr, k))
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