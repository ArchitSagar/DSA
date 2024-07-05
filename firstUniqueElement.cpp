#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> ch(26,0);

        for(int i=0;s[i] != '\0';i++){
            ch[s[i] - 97]++; 
        }

        for(int i =0; s[i] != '\0';i++){
            if(ch[s[i]-97] == 1) return i;
        }

        return -1;
    }
};

int main(){
    Solution sol;
    string s;
    cin >> s;
    int ans = sol.firstUniqChar(s);

    cout << ans << endl;

    return 0;
}