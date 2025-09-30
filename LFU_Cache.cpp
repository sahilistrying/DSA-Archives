/*
 * PROBLEM: LFU Cache
 * PLATFORM: LeetCode
 * DIFFICULTY: Hard
 * LEETCODE URL: https://leetcode.com/problems/lfu-cache/
 * * PROBLEM DESCRIPTION:
 * Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

	LFUCache(int capacity) Initializes the object with the capacity of the data structure.
	int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
	void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.

To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.
 * * APPROACH:
 * Solved using Hash Table to optimize the approach.
 * Topics: Hash Table, Linked List, Design, Doubly-Linked List
 */

#include <bits/stdc++.h>
using namespace std;

class LFUCache {
public:
    int capacity; // max number of items that can be stored
    int minFreq;  // current minimum frequency
    unordered_map<int, pair<int, int>> keyToValFreq; // key -> {value, freq}
    unordered_map<int, list<int>> freqToKeys; // freq -> list of keys
    unordered_map<int, list<int>::iterator> keyToIter; // key -> iterator in freqToKeys[freq]

    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }

    int get(int key) {
        if (capacity == 0) return -1;
        if (!keyToValFreq.count(key)) return -1;

        // Get current value and frequency
        int val = keyToValFreq[key].first;
        int freq = keyToValFreq[key].second;

        // Remove key from its current frequency list
        freqToKeys[freq].erase(keyToIter[key]);

        // If this freq list is empty and it was minFreq, increment minFreq
        if (freqToKeys[freq].empty()) {
            freqToKeys.erase(freq);
            if (minFreq == freq) minFreq++;
        }

        // Add key to freq+1 list
        freqToKeys[freq + 1].push_front(key);
        keyToIter[key] = freqToKeys[freq + 1].begin();

        // Update frequency
        keyToValFreq[key].second++;

        return val;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        // If key exists, update value and increase freq
        if (keyToValFreq.count(key)) {
            keyToValFreq[key].first = value;
            get(key); // reuse get() logic to update frequency
            return;
        }

        // If capacity full, evict LFU (least frequently used)
        if (keyToValFreq.size() == capacity) {
            int keyToRemove = freqToKeys[minFreq].back(); // least recently used in minFreq
            freqToKeys[minFreq].pop_back();
            if (freqToKeys[minFreq].empty()) freqToKeys.erase(minFreq);
            keyToValFreq.erase(keyToRemove);
            keyToIter.erase(keyToRemove);
        }

        // Insert new key with freq 1
        keyToValFreq[key] = {value, 1};
        freqToKeys[1].push_front(key);
        keyToIter[key] = freqToKeys[1].begin();
        minFreq = 1;
    }
};


// Time Complexity: O(N)
// Space Complexity: O(N) (Recursive Stack)
