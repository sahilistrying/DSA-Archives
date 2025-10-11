/*
 * PROBLEM: Sum of Good Numbers
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/sum-of-good-numbers/
 * * PROBLEM DESCRIPTION:
 * Given an array of integers nums and an integer k, an element nums[i] is considered good if it is strictly greater than the elements at indices i - k and i + k (if those indices exist). If neither of these indices exists, nums[i] is still considered good.

Return the sum of all the good elements in the array.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array
 */

class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(i-k<0){
                if(nums[i]>nums[i+k]) ans+=nums[i];
                continue;
            } 
            if(i+k>=nums.size()){
                if(nums[i]>nums[i-k]) ans+=nums[i];
                continue;
            }     
            if(nums[i]>nums[i+k] && nums[i]>nums[i-k]) ans+=nums[i];
        }
        return ans;
    }

};

// Time Complexity: O(N)
// Space Complexity: O(1)
