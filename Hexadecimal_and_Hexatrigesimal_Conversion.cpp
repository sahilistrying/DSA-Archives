/*
 * PROBLEM: Hexadecimal and Hexatrigesimal Conversion
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/hexadecimal-and-hexatrigesimal-conversion/
 * * PROBLEM DESCRIPTION:
 * You are given an integer n.

Return the concatenation of the hexadecimal representation of n2 and the hexatrigesimal representation of n3.

A hexadecimal number is defined as a base-16 numeral system that uses the digits 0 – 9 and the uppercase letters A - F to represent values from 0 to 15.

A hexatrigesimal number is defined as a base-36 numeral system that uses the digits 0 – 9 and the uppercase letters A - Z to represent values from 0 to 35.
 * * APPROACH:
 * Solved using Math to optimize the approach.
 * Topics: Math, String
 */

class Solution {
public:
    string concatHex36(int n) {

        string hex = "", base36 = "";
        long long n2 = n*n;
        long long n3 = n2* n;
        string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        long long temp = n2;
        if (temp == 0) hex = "0";
        while (temp) {
            hex += chars[temp % 16];
            temp /= 16;
        }
        reverse(hex.begin(), hex.end());
    
        temp = n3;
        if (temp == 0) base36 = "0";
        while (temp) {
            base36 += chars[temp % 36];
            temp /= 36;
        }
        reverse(base36.begin(), base36.end());
    
        return hex + base36;

    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
