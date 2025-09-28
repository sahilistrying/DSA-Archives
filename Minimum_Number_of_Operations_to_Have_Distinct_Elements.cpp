/*
 * PROBLEM: Minimum Number of Operations to Have Distinct Elements
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/minimum-number-of-operations-to-have-distinct-elements/
 * * PROBLEM DESCRIPTION:
 * You are given an integer array nums.

In one operation, you remove the first three elements of the current array. If there are fewer than three elements remaining, all remaining elements are removed.

Repeat this operation until the array is empty or contains no duplicate values.

Return an integer denoting the number of operations required.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Hash Table
 */

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int nin=nums.size();
        int pos=INT_MIN;
        unordered_map<int,int> stt;
        for(auto it:nums) stt[it]++;
        for(int i=0;i<nin;i++){
            if(stt[nums[i]]>1 ) {
                stt[nums[i]]--;
                pos=i+1;
          
            }
        }
        //cout<<"check"<<pos<<endl;
        if(pos==INT_MIN) return 0;
        return ceil(pos/3.0);
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
