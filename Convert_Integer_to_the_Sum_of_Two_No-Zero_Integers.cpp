/*
 * PROBLEM: Convert Integer to the Sum of Two No-Zero Integers
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/
 * * PROBLEM DESCRIPTION:
 * No-Zero integer is a positive integer that does not contain any 0 in its decimal representation.

Given an integer n, return a list of two integers [a, b] where:

	a and b are No-Zero integers.
	a + b = n

The test cases are generated so that there is at least one valid solution. If there are many valid solutions, you can return any of them.
 * * APPROACH:
 * Solved using Math to optimize the approach.
 * Topics: Math
 */

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        auto check = [](int x) {
                        while (x > 0) {
                                        if (x % 10 == 0) return false;
                                                        x /= 10;
                                                                    }
                                                                                return true;
                                                                                        };
                                                                                                for (int i = 1; i < n; ++i) {
                                                                                                            int j = n - i;
                                                                                                                        if (check(i) && check(j)) {
                                                                                                                                        return {i, j};
                                                                                                                                                    }
                                                                                                                                                            }
                                                                                                                                                                    return {};
        }
    
};

// Time Complexity: O(N)
// Space Complexity: O(1)
