/*
 * PROBLEM: Smallest Index With Digit Sum Equal to Index
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/
 * * PROBLEM DESCRIPTION:
 * You are given an integer array nums.

Return the smallest index i such that the sum of the digits of nums[i] is equal to i.

If no such index exists, return -1.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Math
 */

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int val=nums[i];
            int num=0;
            while(val){
                num+=val%10;
                val=val/10;
            }
            if(num==i){
                return i;
            }
        }
        return -1;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
