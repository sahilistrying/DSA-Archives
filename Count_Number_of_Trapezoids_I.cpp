/*
 * PROBLEM: Count Number of Trapezoids I
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/count-number-of-trapezoids-i/
 * * PROBLEM DESCRIPTION:
 * You are given a 2D integer array points, where points[i] = [xi, yi] represents the coordinates of the ith point on the Cartesian plane.

A horizontal trapezoid is a convex quadrilateral with at least one pair of horizontal sides (i.e. parallel to the x-axis). Two lines are parallel if and only if they have the same slope.

Return the  number of unique horizontal trapezoids that can be formed by choosing any four distinct points from points.

Since the answer may be very large, return it modulo 109 + 7.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Hash Table, Math, Geometry
 */

class Solution {
public:
    static int countTrapezoids(vector<vector<int>>& points) {
        const long long mod=1e9+7, n=points.size();
        int* y=(int*)alloca(n*sizeof(int));
        int i=0;
        for(auto& p: points) y[i++]=p[1];
        sort(y, y+n);
        long long sum=0, c2=0, c=0;
        int f=1, prev=y[0];
        for(int i=1; i<n; i++){
            if (prev==y[i]) f++;
            else{
                c=f*(f-1LL)/2LL;
                sum+=c;
                c2+=c*c;
                f=1;
                prev=y[i];
            }
        }
        c=f*(f-1LL)/2LL;
        sum+=c;
        c2+=c*c;
        return (sum*sum-c2)/2%mod;

    }
};

// Time Complexity: O(N log N)
// Space Complexity: O(N^2)
