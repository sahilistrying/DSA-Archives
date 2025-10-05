/*
 * PROBLEM: Smallest All-Ones Multiple
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/smallest-all-ones-multiple/
 * * PROBLEM DESCRIPTION:
 * You are given a positive integer k.

Find the smallest integer n divisible by k that consists of only the digit 1 in its decimal representation (e.g., 1, 11, 111, ...).

Return an integer denoting the number of digits in the decimal representation of n. If no such n exists, return -1.
 * * APPROACH:
 * Solved using Hash Table to optimize the approach.
 * Topics: Hash Table, Math
 */

class Solution {
public:
    int minAllOneMultiple(int k) {
        if(k%2==0 || k%5==0) return -1;
        int tandori=k;
        int remider=0;
        for(int ll=1;ll<=tandori;ll++){
            remider=(remider*10+1)%tandori;
            if(remider==0) return ll;
        }
        return -1;
    }
    
};

// Time Complexity: O(N)
// Space Complexity: O(1)
