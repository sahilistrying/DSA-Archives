/*
 * PROBLEM: Minimum Moves to Balance Circular Array
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/minimum-moves-to-balance-circular-array/
 * * PROBLEM DESCRIPTION:
 * You are given a circular array balance of length n, where balance[i] is the net balance of person i.

In one move, a person can transfer exactly 1 unit of balance to either their left or right neighbor.

Return the minimum number of moves required so that every person has a non-negative balance. If it is impossible, return -1.

Note: You are guaranteed that at most 1 index has a negative balance initially.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Greedy, Sorting
 */

class Solution {
public:
    long long minMoves(vector<int>& balance) {
        long long tot=balance.size();
        long long ans=0;
        long long summ=0;
        int neggg=-1;
        for(int i=0;i<tot;i++){
            summ+=balance[i];
            if(balance[i]<0) neggg=i;
        }
        if(summ<0) return -1;
        if(neggg==-1) return 0;

        long long mov=0;
        long long needd=abs(balance[neggg]);

        for(int distt=1;distt<=tot/2;distt++){
            int rr=(neggg+distt)%tot;
            if(balance[rr]>0){
                long long tak=min((long long)balance[rr],needd);
                mov+=tak*distt;
                needd-=tak;
                balance[rr]-=tak;
                
            }
            if(needd==0)break;

            int ll=(neggg-distt+tot)%tot;
            if(ll!=rr && balance[ll]>0){
                long long tak=min((long long)balance[ll],needd);
                mov+=tak*distt;
                needd-=tak;
                balance[ll]-=tak;
            
            }
            if(needd==0) break;
        }
        return mov;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
