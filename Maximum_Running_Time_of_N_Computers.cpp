/*
 * PROBLEM: Maximum Running Time of N Computers
 * PLATFORM: LeetCode
 * DIFFICULTY: Hard
 * LEETCODE URL: https://leetcode.com/problems/maximum-running-time-of-n-computers/
 * * PROBLEM DESCRIPTION:
 * You have n computers. You are given the integer n and a 0-indexed integer array batteries where the ith battery can run a computer for batteries[i] minutes. You are interested in running all n computers simultaneously using the given batteries.

Initially, you can insert at most one battery into each computer. After that and at any integer time moment, you can remove a battery from a computer and insert another battery any number of times. The inserted battery can be a totally new battery or a battery from another computer. You may assume that the removing and inserting processes take no time.

Note that the batteries cannot be recharged.

Return the maximum number of minutes you can run all the n computers simultaneously.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Binary Search, Greedy, Sorting
 */

class Solution {
public:
    static long long maxRunTime(int n, vector<int>& batteries) {
        const long long sum=reduce(batteries.begin(), batteries.end(), 0LL);
        long long l=*min_element(batteries.begin(), batteries.end()), r=sum/n, ans=0;   

        while (l<=r) {
            long long mid=(l+r)>>1;
            long long reserve=0;

            for (int x : batteries)
                reserve+=min((long long)x, mid);

            if (reserve>=mid*n) {
                ans=mid;     
                l=mid+1;     
            } 
            else 
                r=mid-1;  
        }
        return ans;  
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N) (Recursive Stack)
