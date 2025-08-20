/*
 * PROBLEM: Maximum Balanced Shipments
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/maximum-balanced-shipments/
 * * PROBLEM DESCRIPTION:
 * You are given an integer array weight of length n, representing the weights of n parcels arranged in a straight line. A shipment is defined as a contiguous subarray of parcels. A shipment is considered balanced if the weight of the last parcel is strictly less than the maximum weight among all parcels in that shipment.

Select a set of non-overlapping, contiguous, balanced shipments such that each parcel appears in at most one shipment (parcels may remain unshipped).

Return the maximum possible number of balanced shipments that can be formed.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Dynamic Programming, Stack, Greedy, Monotonic Stack
 */

class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int i=0;
        int ans=0;
        int maxe=INT_MIN;
        while(i<weight.size()){
            maxe=max(maxe,weight[i]);
            if(maxe<=weight[i]){
                i++;
                continue;
            }
            else{
                maxe=INT_MIN;
                ans++;
                i++;
            }

        }
        return ans;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
