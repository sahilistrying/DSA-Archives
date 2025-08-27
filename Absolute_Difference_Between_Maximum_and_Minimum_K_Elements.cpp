/*
 * PROBLEM: Absolute Difference Between Maximum and Minimum K Elements
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/absolute-difference-between-maximum-and-minimum-k-elements/
 * * PROBLEM DESCRIPTION:
 * You are given an integer array nums and an integer k.

Find the absolute difference between:

	the sum of the k largest elements in the array; and
	the sum of the k smallest elements in the array.

Return an integer denoting this difference.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Sorting
 */

class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int lar=0,smal=0;
        for(int i=0;i<k;i++){
            smal+=nums[i];
        }
        reverse(nums.begin(),nums.end());
        for(int i=0;i<k;i++){
            lar+=nums[i];
        }
        return abs(lar-smal);
    }
};

// Time Complexity: O(N log N)
// Space Complexity: O(1)
