/*
 * PROBLEM: Count Collisions on a Road
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/count-collisions-on-a-road/
 * * PROBLEM DESCRIPTION:
 * There are n cars on an infinitely long road. The cars are numbered from 0 to n - 1 from left to right and each car is present at a unique point.

You are given a 0-indexed string directions of length n. directions[i] can be either 'L', 'R', or 'S' denoting whether the ith car is moving towards the left, towards the right, or staying at its current point respectively. Each moving car has the same speed.

The number of collisions can be calculated as follows:

	When two cars moving in opposite directions collide with each other, the number of collisions increases by 2.
	When a moving car collides with a stationary car, the number of collisions increases by 1.

After a collision, the cars involved can no longer move and will stay at the point where they collided. Other than that, cars cannot change their state or direction of motion.

Return the total number of collisions that will happen on the road.
 * * APPROACH:
 * Solved using String to optimize the approach.
 * Topics: String, Stack, Simulation
 */

class Solution {
public:
    int countCollisions(string directions) {
        bool canadd=false;
        int ans=0;
        int toadd=0;
        int n=directions.size();
        int i=-1,j=-1;
        while(j<n){
            j++;
            if(directions[j]=='L'){
                
                
                if(i!=-1 && directions[i]=='R'){
                    ans+=2;
                    ans+=toadd;
                    toadd=0;
                    i=j;
                    directions[i]='S';
                }
                else if(i!=-1 && directions[i]=='S'){
                    ans+=1;
                    ans+=toadd;
                    toadd=0;
                    i=j;
                    directions[i]='S';
                }
                else if(canadd){
                    ans++;
                    continue;
                }
            }
            else if(directions[j]=='S'){
                canadd=true;
                if(i==-1) continue;
                else if(directions[i]=='R'){
                    ans+=1;
                    ans+=toadd;
                    toadd=0;
                    i=j;
                    directions[i]='S';
                }
                
            }
            else{
                if(i!=-1 && directions[i]=='R') toadd++;
                i=j;
            }
        }
        return ans;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
