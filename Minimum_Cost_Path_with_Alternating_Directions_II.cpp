/*
 * PROBLEM: Minimum Cost Path with Alternating Directions II
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/minimum-cost-path-with-alternating-directions-ii/
 * * PROBLEM DESCRIPTION:
 * You are given two integers m and n representing the number of rows and columns of a grid, respectively.

The cost to enter cell (i, j) is defined as (i + 1) * (j + 1).

You are also given a 2D integer array waitCost where waitCost[i][j] defines the cost to wait on that cell.

The path will always begin by entering cell (0, 0) on move 1 and paying the entrance cost.

At each step, you follow an alternating pattern:

	On odd-numbered seconds, you must move right or down to an adjacent cell, paying its entry cost.
	On even-numbered seconds, you must wait in place for exactly one second and pay waitCost[i][j] during that second.

Return the minimum total cost required to reach (m - 1, n - 1).
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Dynamic Programming, Matrix
 */

class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<long long>> dp(m , vector<long long>(n , 0)) ;

        int dr = m -1 , dc = n -1 ;

        for(int r = 0 ; r < m ; r ++ ){
            for(int c = 0 ; c < n ; c ++ ){
                if(r== 0 && c==0){
                    dp[r][c] = 0 ;
                }
                else{
                    long long val = (r + 1) * ( 1LL ) * (c +1 ) ;
                    long long pay = val ;
                    if( !(r == dr && c == dc) ){
                        pay = pay + waitCost[r][c] ;
                    }
                    long long up , lft ;
                    if( r > 0 ){
                        up = dp[r -1][c] ;
                    }
                    else{
                        up = 1e18 ;
                    }
                    if( c > 0 ){
                        lft = dp[r][c - 1] ;
                    }
                    else{
                        lft = 1e18 ;
                    }
                    if( up < lft ){
                        dp[r][c] = pay + up ;
                    }
                    else{
                        dp[r][c] = pay + lft ;
                    }
                }
            }
        }
        return 1 + dp[dr][dc] ;
    }
};


// Time Complexity: O(N)
// Space Complexity: O(N^2)
