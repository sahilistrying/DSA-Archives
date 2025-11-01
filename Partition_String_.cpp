/*
 * PROBLEM: Partition String 
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/partition-string/
 * * PROBLEM DESCRIPTION:
 * Given a string s, partition it into unique segments according to the following procedure:

	Start building a segment beginning at index 0.
	Continue extending the current segment character by character until the current segment has not been seen before.
	Once the segment is unique, add it to your list of segments, mark it as seen, and begin a new segment from the next index.
	Repeat until you reach the end of s.

Return an array of strings segments, where segments[i] is the ith segment created.
 * * APPROACH:
 * Solved using Hash Table to optimize the approach.
 * Topics: Hash Table, String, Trie, Simulation
 */

class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string> recorded;
        vector<string> parts;
        string segment = "";

        for (char letter : s) {
            segment += letter;
            if (recorded.find(segment) == recorded.end()) {
                recorded.insert(segment);
                parts.push_back(segment);
                segment = "";
            }
        }

        return parts;
    }
};


// Time Complexity: O(N)
// Space Complexity: O(N)
