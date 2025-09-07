/*
 * PROBLEM: Calculate Score After Performing Instructions
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/calculate-score-after-performing-instructions/
 * * PROBLEM DESCRIPTION:
 * You are given two arrays, instructions and values, both of size n.

You need to simulate a process based on the following rules:

	You start at the first instruction at index i = 0 with an initial score of 0.
	If instructions[i] is "add":

		Add values[i] to your score.
		Move to the next instruction (i + 1).

	If instructions[i] is "jump":

		Move to the instruction at index (i + values[i]) without modifying your score.

The process ends when you either:

	Go out of bounds (i.e., i < 0 or i >= n), or
	Attempt to revisit an instruction that has been previously executed. The revisited instruction is not executed.

Return your score at the end of the process.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Hash Table, String, Simulation
 */

class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        unordered_set<int> executedIndices;  
        int totalInstructions = instructions.size();

        int currentIndex = 0;
        long long scoreSum = 0;  
        while (currentIndex >= 0 && currentIndex < totalInstructions && 
               (executedIndices.find(currentIndex) == executedIndices.end())) {
            
            executedIndices.insert(currentIndex);
            
            if (instructions[currentIndex] == "jump") {
                currentIndex += values[currentIndex];  
            } else {
                scoreSum += values[currentIndex];  
                currentIndex++;  
            }
        }

        return scoreSum;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
