/*
 * PROBLEM: Find Closest Person
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/find-closest-person/
 * * PROBLEM DESCRIPTION:
 * You are given three integers x, y, and z, representing the positions of three people on a number line:

	x is the position of Person 1.
	y is the position of Person 2.
	z is the position of Person 3, who does not move.

Both Person 1 and Person 2 move toward Person 3 at the same speed.

Determine which person reaches Person 3 first:

	Return 1 if Person 1 arrives first.
	Return 2 if Person 2 arrives first.
	Return 0 if both arrive at the same time.

Return the result accordingly.
 * * APPROACH:
 * Solved using Math to optimize the approach.
 * Topics: Math
 */

class Solution {
public:
    int findClosest(int x, int y, int z) {
      if(abs(z-x)>abs(z-y))return 2;
      else if(abs(z-x)<abs(z-y)) return 1;  
      else return 0;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
