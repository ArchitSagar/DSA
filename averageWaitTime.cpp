
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cus) {
        double avg;
        int n = cus.size();
        int totalTime = cus[0][0] + cus[0][1];
        int waitTime = cus[0][1];
        for(int i = 1; i < n;i++){
            if(cus[i][0] > totalTime){
                totalTime = cus[i][0] + cus[i][1];
                waitTime += cus[i][1];
            }
            else{
                totalTime += cus[i][1];
                waitTime += (totalTime - cus[i][0]);
            }
            cout << waitTime << endl;
        }
        cout << waitTime << endl;
        avg = (double)waitTime/(double)n;
        return avg;

    }
};

int main()
{
    Solution sol;
    vector<vector<int>> cus = {{5,2},{5,4},{10,3},{20,1}};
    double ans = sol.averageWaitingTime(cus);
    std::cout<<"avg = " << ans;

    return 0;
}