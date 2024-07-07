
#include <bits/stdc++.h>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>> n;
        pair<int,int> val;
        int s = temp.size();
        vector<int> ans(s,0);
        for(int i = temp.size()-1;i >= 0;i--){

            while(true){
                
                if(n.empty()){
                    n.push({temp[i],i});
                    ans[i] = 0;
                    break;
                }
                val = n.top();
                if(temp[i] >= val.first){
                    n.pop();
                }
                else{
                    ans[i] = val.second - i;
                    n.push({temp[i],i});
                    break;  
                }

            }
        }
        return ans;
    }

int main()
{
    vector<int> temp = {73,74,75,71,69,72,76,73};
    vector<int> ans;
    
    ans = dailyTemperatures(temp);
    
    for(auto it : ans){
        cout << it << " ";
    }
    
    std::cout<<endl;

    return 0;
}