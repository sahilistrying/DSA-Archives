/*
 * PROBLEM: Unique 3-Digit Even Numbers
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/unique-3-digit-even-numbers/
 * * PROBLEM DESCRIPTION:
 * You are given an array of digits called digits. Your task is to determine the number of distinct three-digit even numbers that can be formed using these digits.

Note: Each copy of a digit can only be used once per number, and there may not be leading zeros.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Hash Table, Recursion, Enumeration
 */

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> s;

        int n = digits.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i != j && j != k && i != k && digits[i] != 0 && digits[k] % 2 == 0) {
                        int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                        s.insert(num);
                    }
                }
            }
        }

        return s.size();
    }
};


// Time Complexity: O(N)
// Space Complexity: O(N)
