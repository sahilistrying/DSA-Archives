/*
 * PROBLEM: How Many Numbers Are Smaller Than the Current Number
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
 * * PROBLEM DESCRIPTION:
 * Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Hash Table, Sorting, Counting Sort
 */

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int,int> mpp;
        vector<int> ans,copy;
        copy=nums;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(mpp[nums[i]]==0) mpp[nums[i]]=i+1;
        }
        for(int i=0;i<nums.size();i++){
            ans.push_back(mpp[copy[i]]-1);
        }
        return ans;
    }
};

// Time Complexity: O(N log N)
// Space Complexity: O(N)
