/*
 * PROBLEM: Sqrt(x)
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/sqrtx/
 * * PROBLEM DESCRIPTION:
 * Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

	For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 * * APPROACH:
 * Solved using Math to optimize the approach.
 * Topics: Math, Binary Search
 */

class Solution {
public:
    int mySqrt(int x) {
        int low=0,high=x;
        int ans=-1;
        while(low<=high){
            long long mid=(low+high)/2;
            if((mid*mid)==x){
                return mid;
            }
            else if(mid*mid>x){
                high=mid-1;
            }
            else{
                ans=mid;
                low=mid+1;
            }
        }
        return ans;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
