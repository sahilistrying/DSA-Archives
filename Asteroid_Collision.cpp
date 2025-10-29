/*
 * PROBLEM: Asteroid Collision
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/asteroid-collision/
 * * PROBLEM DESCRIPTION:
 * We are given an array asteroids of integers representing asteroids in a row. The indices of the asteroid in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Stack, Simulation
 */

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        for(auto it:asteroids){
            bool dontadd=false;
            if(it<0){
                if(st.empty() || st.top()<0) st.push(it);
                else{
                    while(!st.empty() && st.top()>0){
                        int top=st.top();
                        if(top<abs(it)){
                            st.pop();      
                        }
                        else if(top>abs(it)){
                            break;
                        }
                        else{
                            dontadd=true;
                            st.pop(); 
                            break;
                        }
                    }
                    if(!dontadd && (st.empty() || st.top()<0)) st.push(it);
                   
                }
            }
            else if(it>0){
                st.push(it);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


// Time Complexity: O(N)
// Space Complexity: O(1)
