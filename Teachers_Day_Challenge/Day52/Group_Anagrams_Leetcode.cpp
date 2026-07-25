/*
Problem: Group Anagrams
Platform: LeetCode (49)
Topic: Hash Table, String, Sorting

Approach:
1. Create a hash map (unordered_map) where the key is a sorted string and the value is a vector of matching original strings.
2. Iterate through each string in the input array.
3. Create a copy of the string, sort its characters, and use this sorted string as the hash map key.
4. Push the original string into the vector corresponding to its sorted key.
5. Traverse the map and collect all grouped string vectors into the final result vector.

Time Complexity: O(n * k log k)
- Where n is the number of strings and k is the maximum length of a string.
- Sorting each string takes O(k log k) time.

Space Complexity: O(n * k)
- Storing all strings in the hash map and the answer vector requires proportional space.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;

        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            anagramGroups[key].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto& group : anagramGroups) {
            ans.push_back(group.second);
        }

        return ans;
    }
};