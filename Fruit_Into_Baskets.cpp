/*
 * PROBLEM: Fruit Into Baskets
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/fruit-into-baskets/
 * * PROBLEM DESCRIPTION:
 * You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

	You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
	Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
	Once you reach a tree with fruit that cannot fit in your baskets, you must stop.

Given the integer array fruits, return the maximum number of fruits you can pick.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Hash Table, Sliding Window
 */

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0, ans = 0;
        map<int,int> mpp;

        for (int right = 0; right < n; right++) {
            mpp[fruits[right]]++;

            while (mpp.size() > 2) {
                mpp[fruits[left]]--;
                if (mpp[fruits[left]] == 0)
                    mpp.erase(fruits[left]);
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};


// Time Complexity: O(N)
// Space Complexity: O(N)
