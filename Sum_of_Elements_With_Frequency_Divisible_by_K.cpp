/*
 * PROBLEM: Sum of Elements With Frequency Divisible by K
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/sum-of-elements-with-frequency-divisible-by-k/
 * * PROBLEM DESCRIPTION:
 * You are given an integer array nums and an integer k.

Return an integer denoting the sum of all elements in nums whose frequency is divisible by k, or 0 if there are no such elements.

Note: An element is included in the sum exactly as many times as it appears in the array if its total frequency is divisible by k.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Hash Table, Counting
 */

class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int ans= 0; 
        map<int, int> hush; 
        for(int i= 0; i< nums.size(); i++){
            hush[nums[i]]++;
        }

        for(auto pair: hush){
            if(pair.second % k == 0){
                ans+= (pair.first * pair.second); 
            }
        }

        return ans;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
