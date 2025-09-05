/*
 * PROBLEM: Find N Unique Integers Sum up to Zero
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
 * * PROBLEM DESCRIPTION:
 * Given an integer n, return any array containing n unique integers such that they add up to 0.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Math
 */

class Solution {
public:
    vector<int> sumZero(int n) {
       vector<int> ans(n);
               iota(ans.begin(), ans.begin()+n/2, -n/2);
                       iota(ans.end()-n/2, ans.end(), 1);
                               return ans; 
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
