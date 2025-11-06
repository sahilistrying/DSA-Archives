/*
 * PROBLEM: Range Product Queries of Powers
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/range-product-queries-of-powers/
 * * PROBLEM DESCRIPTION:
 * Given a positive integer n, there exists a 0-indexed array called powers, composed of the minimum number of powers of 2 that sum to n. The array is sorted in non-decreasing order, and there is only one way to form the array.

You are also given a 0-indexed 2D integer array queries, where queries[i] = [lefti, righti]. Each queries[i] represents a query where you have to find the product of all powers[j] with lefti <= j <= righti.

Return an array answers, equal in length to queries, where answers[i] is the answer to the ith query. Since the answer to the ith query may be too large, each answers[i] should be returned modulo 109 + 7.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Bit Manipulation, Prefix Sum
 */

class Solution {
public:
    const int mod = 1000000007;

    long long power(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    long long modInverse(long long a) {
        return power(a, mod - 2);
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> powa, prea;
        int i = 0;
        while ((n >> i) > 0) {
            if ((n >> i) & 1) {
                long long val = (1LL << i) % mod;
                if (!prea.empty()) {
                    prea.push_back((prea.back() * val) % mod);
                } else {
                    prea.push_back(val);
                }
                powa.push_back(val);
            }
            i++;
        }

        vector<int> ans;
        for (auto &it : queries) {
            int s = it[0], e = it[1];
            long long up = prea[e];
            if (s > 0) {
                long long inv = modInverse(prea[s - 1]);
                ans.push_back((up * inv) % mod);
            } else {
                ans.push_back(up % mod);
            }
        }
        return ans;
    }
};


// Time Complexity: O(N)
// Space Complexity: O(N^2)
