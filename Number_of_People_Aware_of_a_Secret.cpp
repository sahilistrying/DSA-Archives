/*
 * PROBLEM: Number of People Aware of a Secret
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/number-of-people-aware-of-a-secret/
 * * PROBLEM DESCRIPTION:
 * On day 1, one person discovers a secret.

You are given an integer delay, which means that each person will share the secret with a new person every day, starting from delay days after discovering the secret. You are also given an integer forget, which means that each person will forget the secret forget days after discovering it. A person cannot share the secret on the same day they forgot it, or on any day afterwards.

Given an integer n, return the number of people who know the secret at the end of day n. Since the answer may be very large, return it modulo 109 + 7.
 * * APPROACH:
 * Solved using Dynamic Programming to optimize the approach.
 * Topics: Dynamic Programming, Queue, Simulation
 */

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const long long MOD = 1000000007LL;
        if (n == 1) return 1;
        vector<long long> dp(n+1);
        dp[1] = 1;
        long long window = 0;
        for (int i = 2; i <= n; ++i) {
            int enter = i - delay;
            int exit  = i - forget;
            if (enter >= 1) window = (window + dp[enter]) % MOD;
            if (exit >= 1) window = (window - dp[exit] + MOD) % MOD;
            dp[i] = window;
        }
        long long ans = 0;
        int start = max(1, n - forget + 1);
        for (int i = start; i <= n; ++i) ans = (ans + dp[i]) % MOD;
        return (int)ans;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
