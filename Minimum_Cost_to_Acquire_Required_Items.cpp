/*
 * PROBLEM: Minimum Cost to Acquire Required Items
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/minimum-cost-to-acquire-required-items/
 * * PROBLEM DESCRIPTION:
 * You are given five integers cost1, cost2, costBoth, need1, and need2.

There are three types of items available:

	An item of type 1 costs cost1 and contributes 1 unit to the type 1 requirement only.
	An item of type 2 costs cost2 and contributes 1 unit to the type 2 requirement only.
	An item of type 3 costs costBoth and contributes 1 unit to both type 1 and type 2 requirements.

You must collect enough items so that the total contribution toward type 1 is at least need1 and the total contribution toward type 2 is at least need2.

Return an integer representing the minimum possible total cost to achieve these requirements.
 * * APPROACH:
 * Solved using Math to optimize the approach.
 * Topics: Math, Greedy
 */

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans=0;
        if(cost1+cost2>costBoth){
            int needtill=min(need1,need2);
             ans+=(long long)needtill*costBoth;
            if(need1>needtill){
                int needmore=need1-needtill;
                if(cost1>costBoth) ans+=(long long)needmore*costBoth;
                else ans+= (long long)needmore*cost1;
            }
            if(need2>needtill){
                int needmore=need2-needtill;
                if(cost2>costBoth) ans+=(long long)needmore*costBoth;
                else ans+= (long long)needmore*cost2;
            }
            return ans;
            
        }
        else{
            ans+= ((long long)need1*cost1)+((long long)need2*cost2);
            return ans;
            
        }
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
