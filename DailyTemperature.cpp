
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int s = temp.size();
        vector<int> ans(s, 0);
        stack<int> n;

        for (int i = s - 1; i >= 0; --i) {
            while (!n.empty() && temp[i] >= temp[n.top()]) {
                n.pop();
            }
            if (!n.empty()) {
                ans[i] = n.top() - i;
            }
            n.push(i);
        }

        return ans;
    }
};


int main()
{
    Solution sol;
    vector<int> temp = {73,74,75,71,69,72,76,73};
    vector<int> ans;
    
    ans = sol.dailyTemperatures(temp);
    
    for(auto it : ans){
        cout << it << " ";
    }
    
    std::cout<<endl;

    return 0;
}