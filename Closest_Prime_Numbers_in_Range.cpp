/*
 * PROBLEM: Closest Prime Numbers in Range
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/closest-prime-numbers-in-range/
 * * PROBLEM DESCRIPTION:
 * Given two positive integers left and right, find the two integers num1 and num2 such that:

	left <= num1 < num2 <= right .
	Both num1 and num2 are prime numbers.
	num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.

Return the positive integer array ans = [num1, num2]. If there are multiple pairs satisfying these conditions, return the one with the smallest num1 value. If no such numbers exist, return [-1, -1].
 * * APPROACH:
 * Solved using Math to optimize the approach.
 * Topics: Math, Number Theory
 */

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int>ans;
        int firstp=0,secondp=0;
        int diff=INT_MAX;
      for(int i=left;i<=right+1;i++){
        if(firstp!=0 && secondp!=0){
            int couldbe=secondp-firstp;
            if(couldbe<diff){
                diff=couldbe;
                ans.clear();
                ans.push_back(firstp);
                ans.push_back(secondp);
            }
            firstp=secondp;
            secondp=0;
            
        }
        if(isPrime(i) && i<=right){
            if(firstp==0) firstp=i;
            else secondp=i;
        }
      }
      if(ans.size()==0){
        ans.push_back(-1);
        ans.push_back(-1);
      } 
      return ans;  
    }
    bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
