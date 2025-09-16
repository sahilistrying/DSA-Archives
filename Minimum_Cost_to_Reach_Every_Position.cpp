/*
 * PROBLEM: Minimum Cost to Reach Every Position
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/minimum-cost-to-reach-every-position/
 * * PROBLEM DESCRIPTION:
 * You are given an integer array cost of size n. You are currently at position n (at the end of the line) in a line of n + 1 people (numbered from 0 to n).

You wish to move forward in the line, but each person in front of you charges a specific amount to swap places. The cost to swap with person i is given by cost[i].

You are allowed to swap places with people as follows:

	If they are in front of you, you must pay them cost[i] to swap with them.
	If they are behind you, they can swap with you for free.

Return an array answer of size n, where answer[i] is the minimum total cost to reach each position i in the line.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array
 */

class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        vector<int> ans;
        int minv=INT_MAX;
        for(int i=0;i<cost.size();i++){
            minv=min(minv,cost[i]);
            ans.push_back(minv);
        }
        return ans;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
