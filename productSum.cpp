#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int i = 0;
        ans[i] = 1;

        for(i = 1;i<n;i++){
            ans[i] = ans[i-1] * nums[i - 1];
        }
        
        int right = 1;
        for(int j = n-1; j >= 0; j--){
            ans[j] *= right;
            right *= nums[j];
        }

        return ans;

    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,3,4};
    vector<int> ans;
    
    ans = sol.productExceptSelf(nums);
    
    for(auto it : ans){
        cout << it << " ";
    }
    cout << endl;
}
