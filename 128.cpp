// Longest Consecutive Sequence

// Medium
// Topics
// Companies


// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

 

// Example 1:

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int maxi  = 1;
        unordered_set<int> val;
        for(auto it : nums){
            val.insert(it);
        }
        for(auto it : val){
            if(val.find(it -1) == val.end()){
                int cnt = 1;
                int x = it;
                while(val.find(x+1) != val.end()){
                    x = x + 1;
                    cnt = cnt + 1;
                }
                maxi = max(cnt,maxi);
            }
        }

        return maxi;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {100,4,200,1,3,2};
    int ans = sol.longestConsecutive(v);
    std::cout<<"ans = " << ans;

    return 0;
}