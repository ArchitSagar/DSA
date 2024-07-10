
// Longest Substring Without Repeating Characters

// Medium
// Topics
// Companies
// Hint
// Given a string s, find the length of the longest 
// substring
//  without repeating characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> ch;
        int l = 0,r = 0;
        int maxCount = 0;
        while(r < s.size()){
            if(ch.find(s[r]) == ch.end()){
                ch.insert(s[r]);
                r++;
                int count = r - l;
                maxCount = max(maxCount,count);
            }
            else{
                ch.erase(s[l]);
                l++;
            }
        }
        return maxCount;
    }
};

int main()
{
    Solution sol;
    string s = "abcabcbb";
    int ans = sol.lengthOfLongestSubstring(s);
    cout<<"ans = " << ans;

    return 0;
}