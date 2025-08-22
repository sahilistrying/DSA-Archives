/*
 * PROBLEM: Longest Strictly Increasing or Strictly Decreasing Subarray
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/
 * * PROBLEM DESCRIPTION:
 * You are given an array of integers nums. Return the length of the longest subarray of nums which is either strictly increasing or strictly decreasing.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array
 */

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int tot=nums.size();
        int decmax=1;
        int incmax=1;
        int cntd=1;
        int cnti=1;
        for(int i=0;i<tot-1;i++){
            //dec
            if(nums[i]>nums[i+1]){
                cntd++;
                decmax=max(decmax,cntd);
            }
            else{
                cntd=1;
            }


            if(nums[i]<nums[i+1]){
                cnti++;
                incmax=max(incmax,cnti);
            }
            else{
                cnti=1;
            }

        }
        return max(decmax,incmax);
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
