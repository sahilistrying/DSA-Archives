/*
 * PROBLEM: Coupon Code Validator
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/coupon-code-validator/
 * * PROBLEM DESCRIPTION:
 * You are given three arrays of length n that describe the properties of n coupons: code, businessLine, and isActive. The ith coupon has:

	code[i]: a string representing the coupon identifier.
	businessLine[i]: a string denoting the business category of the coupon.
	isActive[i]: a boolean indicating whether the coupon is currently active.

A coupon is considered valid if all of the following conditions hold:

	code[i] is non-empty and consists only of alphanumeric characters (a-z, A-Z, 0-9) and underscores (_).
	businessLine[i] is one of the following four categories: "electronics", "grocery", "pharmacy", "restaurant".
	isActive[i] is true.

Return an array of the codes of all valid coupons, sorted first by their businessLine in the order: "electronics", "grocery", "pharmacy", "restaurant", and then by code in lexicographical (ascending) order within each category.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Hash Table, String, Sorting
 */

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n=code.size() ;
        vector<pair<int,string>> z ;

        unordered_map<string,int> u ;
        u["electronics"]=0 ;
        u["grocery"]=1 ;
        u["pharmacy"]=2 ;
        u["restaurant"]=3 ;

        for(int j=0;j<n;j++){
            string s=code[j] ;
            string t=businessLine[j] ;
            bool f=isActive[j] ;

            if(s.size()==0) continue ;

            bool yes=1 ;
            for(char c:s){
                if(!(isalnum(c)||c=='_')){
                    yes=0 ;
                    break ;
                }
            }

            if(yes&&u.count(t)&&f){
                z.push_back({u[t],s}) ;
            }
        }

        sort(z.begin(),z.end()) ;
        vector<string> fin ;
        for(auto& k:z) fin.push_back(k.second) ;
        return fin ;
    }
};


// Time Complexity: O(N log N)
// Space Complexity: O(N)
