/*
 * PROBLEM: Partition Array Into Two Arrays to Minimize Sum Difference
 * PLATFORM: LeetCode
 * DIFFICULTY: Hard
 * LEETCODE URL: https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/
 * * PROBLEM DESCRIPTION:
 * You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.

Return the minimum possible absolute difference.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Two Pointers, Binary Search, Dynamic Programming, Bit Manipulation, Ordered Set, Bitmask
 */

class Solution {
public:
    int solve(vector<int> &sums1,vector<int> &sums2,int ts,int n){
        int ans=INT_MAX;
        for(auto it:sums1){
            int target=ts/2-it;
            int lb=lower_bound(sums2.begin(),sums2.end(),target)-sums2.begin();
            if(lb==sums2.size()){
                ans=min(ans,abs(ts-2*(sums2[lb-1]+it)));
            }
            else if(lb==0){
                ans=min(ans,abs(ts-2*(sums2[lb]+it)));
            }
            else{
                ans=min(ans,min(abs(ts-2*(sums2[lb]+it)),abs(ts-2*(sums2[lb-1]+it))));
            }
        }
        return ans;
    }
    int minimumDifference(vector<int>& nums) {
      int m=nums.size();
      int n=m/2;
      int ts=0;
      vector<int>arr1(n),arr2(n);
      for(int i=0;i<n;i++){
        arr1[i]=nums[i];
        arr2[i]=nums[i+n];
        ts+=nums[i]+nums[i+n];

      }
      vector<int> sums1[n+1],sums2[n+1];
      for(int i=0;i<(1<<n);i++){
        int tot1=0,tot2=0,count=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                tot1+=arr1[j];
                tot2+=arr2[j];
                count++;
            }
           
        }
            sums1[count].push_back(tot1);
            sums2[count].push_back(tot2);
      }
        for(int i=0;i<=n;i++){
            sort(sums2[i].begin(),sums2[i].end());
        }
        int ans=INT_MAX;
        for(int i=0;i<=n;i++){
            ans=min(ans,solve(sums1[i],sums2[n-i],ts,n));
        }
      
        return ans;
    }
};

// Time Complexity: O(N log N)
// Space Complexity: O(N) (Recursive Stack)
