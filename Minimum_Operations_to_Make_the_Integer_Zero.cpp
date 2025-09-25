/*
 * PROBLEM: Minimum Operations to Make the Integer Zero
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/
 * * PROBLEM DESCRIPTION:
 * You are given two integers num1 and num2.

In one operation, you can choose integer i in the range [0, 60] and subtract 2i + num2 from num1.

Return the integer denoting the minimum number of operations needed to make num1 equal to 0.

If it is impossible to make num1 equal to 0, return -1.
 * * APPROACH:
 * Solved using Bit Manipulation to optimize the approach.
 * Topics: Bit Manipulation, Brainteaser, Enumeration
 */

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int k = 1; k <= 60; k++) {
            long long x = num1 - 1LL * num2 * k;
            if (x < k) {
                return -1;
            }
            if (k >= __builtin_popcountll(x)) {
                return k;
            }
        }
        return -1;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
