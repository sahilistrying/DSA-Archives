/*
 * PROBLEM: Find the Number of Ways to Place People II
 * PLATFORM: LeetCode
 * DIFFICULTY: Hard
 * LEETCODE URL: https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/
 * * PROBLEM DESCRIPTION:
 * You are given a 2D array points of size n x 2 representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

We define the right direction as positive x-axis (increasing x-coordinate) and the left direction as negative x-axis (decreasing x-coordinate). Similarly, we define the up direction as positive y-axis (increasing y-coordinate) and the down direction as negative y-axis (decreasing y-coordinate)

You have to place n people, including Alice and Bob, at these points such that there is exactly one person at every point. Alice wants to be alone with Bob, so Alice will build a rectangular fence with Alice's position as the upper left corner and Bob's position as the lower right corner of the fence (Note that the fence might not enclose any area, i.e. it can be a line). If any person other than Alice and Bob is either inside the fence or on the fence, Alice will be sad.

Return the number of pairs of points where you can place Alice and Bob, such that Alice does not become sad on building the fence.

Note that Alice can only build a fence with Alice's position as the upper left corner, and Bob's position as the lower right corner. For example, Alice cannot build either of the fences in the picture below with four corners (1, 1), (1, 3), (3, 1), and (3, 3), because:

	With Alice at (3, 3) and Bob at (1, 1), Alice's position is not the upper left corner and Bob's position is not the lower right corner of the fence.
	With Alice at (1, 3) and Bob at (1, 1) (as the rectangle shown in the image instead of a line), Bob's position is not the lower right corner of the fence.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Math, Geometry, Sorting, Enumeration
 */

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size();
        auto lambda=[](vector<int>&p1,vector<int>&p2){
            if(p1[0]==p2[0]){
                if(p1[1]>p2[1]) return true;
                else return false;
            }
            else if(p1[0]<p2[0]) return true;
            else return false;
        };
        sort(points.begin(),points.end(),lambda);
        int ans=0;
        for(int i=0;i<n;i++){
            int curx=points[i][0];
            int cury=points[i][1];
            int maxy=INT_MIN;
            for(int j=i+1;j<n;j++){
                int somx=points[j][0];
                int somy=points[j][1];
                
                if(cury>=somy){
                    if(maxy<somy) {
                        ans++;
                        maxy=max(maxy,somy);
                    }
                }
                
            }
        }
        return ans;
    }
};

// Time Complexity: O(N log N)
// Space Complexity: O(N) (Recursive Stack)
