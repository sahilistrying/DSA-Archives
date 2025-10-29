/*
 * PROBLEM: Minimum Operations to Make Array Elements Zero
 * PLATFORM: LeetCode
 * DIFFICULTY: Hard
 * LEETCODE URL: https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/
 * * PROBLEM DESCRIPTION:
 * You are given a 2D array queries, where queries[i] is of the form [l, r]. Each queries[i] defines an array of integers nums consisting of elements ranging from l to r, both inclusive.

In one operation, you can:

	Select two integers a and b from the array.
	Replace them with floor(a / 4) and floor(b / 4).

Your task is to determine the minimum number of operations required to reduce all elements of the array to zero for each query. Return the sum of the results for all queries.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Math, Bit Manipulation
 */

class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        vector<long long> pow4{1};
        while (pow4.back() <= 1000000000LL){
            pow4.push_back(pow4.back() * 4);
        }
        vector<long long> prefix{0};
        for (int i = 0; i < (int)pow4.size() - 1; i++){
            prefix.push_back(prefix.back() + (long long)(i + 1) * 3 * pow4[i]);
        }
        auto F = [&](long long n){
            if (n <= 0)
                return 0LL;
            int k = upper_bound(pow4.begin(), pow4.end(), n) - pow4.begin() - 1;
            return prefix[k] + (long long)(k + 1) * (n - pow4[k] + 1);
        };
        long long res  = 0;
        for (auto &q : queries){
            int l = q[0], r = q[1];
            long s = F(r) - F(l - 1);
            res += (s + 1) / 2;
        }
        return res;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N) (Recursive Stack)
