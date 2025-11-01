/*
 * PROBLEM: Count Partitions with Even Sum Difference
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/count-partitions-with-even-sum-difference/
 * * PROBLEM DESCRIPTION:
 * You are given an integer array nums of length n.

A partition is defined as an index i where 0 <= i < n - 1, splitting the array into two non-empty subarrays such that:

	Left subarray contains indices [0, i].
	Right subarray contains indices [i + 1, n - 1].

Return the number of partitions where the difference between the sum of the left and right subarrays is even.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Math, Prefix Sum
 */

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int tot=0;
        for(auto it:nums) tot+=it;
        int tillsum=0;
        int ans=0;
        for(int i=0;i<nums.size()-1;i++){
            tillsum+=nums[i];
            if((tot-2*tillsum)%2==0) ans++;
        }
        return ans;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
