/*
 * PROBLEM: Maximum Average Pass Ratio
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/maximum-average-pass-ratio/
 * * PROBLEM DESCRIPTION:
 * There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.

You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.

The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.

Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Greedy, Heap (Priority Queue)
 */

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        priority_queue<pair<double,int>> maxheap;
        for(int i=0;i<n;i++){
            double ini=(double)classes[i][0]/classes[i][1];
            double fin=(double)(classes[i][0]+1)/(classes[i][1]+1);
            double delta=fin-ini;
            maxheap.push({delta,i});

        }
        while(extraStudents--){
            auto smtg=maxheap.top();
            maxheap.pop();
            int idx=smtg.second;
            classes[idx][0]++;
            classes[idx][1]++;

            double ini=(double)classes[idx][0]/classes[idx][1];
            double fin=(double)(classes[idx][0]+1)/(classes[idx][1]+1);
            double delta=(double)fin-ini;
            maxheap.push({delta,idx});
        }
        double res=0.0;
        for(int i=0;i<n;i++){
            res+=(double)classes[i][0]/classes[i][1];
        }
        return res/n;
    }
};

// Time Complexity: O(N log N)
// Space Complexity: O(N^2)
