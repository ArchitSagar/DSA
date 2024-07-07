#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
    vector<int> v;
    for(int i =1;i<=n;i++){
        v.push_back(i);
    }
    int  x = k-1, z = n;
    int toDelete = 0;

    while(v.size() != 1){
        toDelete =  (toDelete + x) % z;
        v.erase(v.begin() + toDelete);
        z--;
        if(toDelete == z){
            toDelete = 0;
        }

    }
    return v[0];
    }
};

int main(){
    Solution sol;
    int n = 5, k = 2;
    int ans = sol.findTheWinner(n,k);
    cout << "ans = " << ans << endl;
    return 0;
}