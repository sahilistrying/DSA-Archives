/*
 * PROBLEM: Maximum Unique Subarray Sum After Deletion
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/
 * * PROBLEM DESCRIPTION:
 * You are given an integer array nums.

You are allowed to delete any number of elements from nums without making it empty. After performing the deletions, select a subarray of nums such that:

	All elements in the subarray are unique.
	The sum of the elements in the subarray is maximized.

Return the maximum sum of such a subarray.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Hash Table, Greedy
 */

class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> unq(nums.begin(), nums.end());
        int negCount= 0; 
        int sum= 0;
        
        for(auto it: unq){
            if(it < 0) {
                negCount++;
            }
        }
        
        if(negCount == unq.size()){
            return *max_element(unq.begin(), unq.end());
        } else {
            for(auto it: unq){
                if(it > 0){
                    sum += it;
                }
            }
            
            return sum;
        }
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
