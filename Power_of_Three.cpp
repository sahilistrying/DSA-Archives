/*
 * PROBLEM: Power of Three
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/power-of-three/
 * * PROBLEM DESCRIPTION:
 * Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.
 * * APPROACH:
 * Solved using Math to optimize the approach.
 * Topics: Math, Recursion
 */

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        double loge=log(n)/log(3);
        return fabs(loge-round(loge))<1e-10;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
