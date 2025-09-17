/*
 * PROBLEM: Number of Centered Subarrays
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/number-of-centered-subarrays/
 * * PROBLEM DESCRIPTION:
 * You are given an integer array nums.

A subarray of nums is called centered if the sum of its elements is equal to at least one element within that same subarray.

Return the number of centered subarrays of nums.
 * * APPROACH:
 * Implemented an optimized solution.
 * Topics: Algorithms
 */

class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int ni=nums.size();
        int couldbeans=0;
        for(int i=0;i<ni;i++){
            set<int> smtg;
            int thisshi=0;
            for(int j=i;j<ni;j++){
                smtg.insert(nums[j]);
                thisshi+=nums[j];
                if(smtg.count(thisshi)){
                    couldbeans++;
                    //cout<<"cbeck  "<<thisshi<<endl;
                } 
                
            }
        }
        return couldbeans;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
