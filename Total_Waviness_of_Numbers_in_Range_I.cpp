/*
 * PROBLEM: Total Waviness of Numbers in Range I
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/
 * * PROBLEM DESCRIPTION:
 * You are given two integers num1 and num2 representing an inclusive range [num1, num2].

The waviness of a number is defined as the total count of its peaks and valleys:

	A digit is a peak if it is strictly greater than both of its immediate neighbors.
	A digit is a valley if it is strictly less than both of its immediate neighbors.
	The first and last digits of a number cannot be peaks or valleys.
	Any number with fewer than 3 digits has a waviness of 0.

Return the total sum of waviness for all numbers in the range [num1, num2].
 * * APPROACH:
 * Solved using Math to optimize the approach.
 * Topics: Math, Dynamic Programming, Enumeration
 */

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        set<int>st;
        for(int i=10;i<99;i++){
            string ss="0";
            ss+=(to_string(i));
            vector<int>arr(3);

            for(int it=0;it<3;it++){
                arr[it]=ss[it]-'0';
            }
            //cout<<"check "<<ss<<" ";
            if(arr[0]>arr[1] && arr[1]<arr[2]) st.insert(stoi(ss)); 
            if(arr[0]<arr[1] && arr[1]>arr[2]) st.insert(stoi(ss)); 
        }
        for(int i=100;i<1000;i++){
            string s=to_string(i);
            vector<int>arr(3);
            for(int it=0;it<3;it++){
                arr[it]=s[it]-'0';
            }
            if(arr[0]>arr[1] && arr[1]<arr[2]) st.insert(i); 
            if(arr[0]<arr[1] && arr[1]>arr[2]) st.insert(i); 

        }
        int ans=0;
        for(int i=num1;i<=num2;i++){
            string s=to_string(i);
            string toc="";
            for(char it:s){
                if(toc.size()==3){
                    //cout<<"check "<<toc<<" ";
                   
            
                    int che=stoi(toc);
                 //   cout<<"in if"<<che<<" "<<ans<<endl;
                    if(st.count(che)) ans++;
                    toc.erase(0,1);
                   // cout<<"in if"<<che<<" "<<ans<<endl;
                    
                }
                toc+=it;

                
            }
           // cout<<"  "<<toc<<toc.size()<<endl;
            if(toc.size()==3){
                    int che=stoi(toc);
                 //   cout<<"in if"<<che<<" "<<ans<<endl;
                    if(st.count(che)) ans++;
                   // cout<<"in if"<<che<<" "<<ans<<endl;

            }
        }
        return ans;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
