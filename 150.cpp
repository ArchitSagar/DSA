//  Evaluate Reverse Polish Notation

// Medium
// Topics
// Companies
// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

// Evaluate the expression. Return an integer that represents the value of the expression.

// Note that:

// The valid operators are '+', '-', '*', and '/'.
// Each operand may be an integer or another expression.
// The division between two integers always truncates toward zero.
// There will not be any division by zero.
// The input represents a valid arithmetic expression in a reverse polish notation.
// The answer and all the intermediate calculations can be represented in a 32-bit integer.
 

// Example 1:

// Input: tokens = ["2","1","+","3","*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int calAns(int v1, int v2, string it){
        if(it == "+") return v1 + v2;
        else if(it == "*") return v1 * v2;
        else if(it == "/") return v1 / v2;
        else return v1 - v2;
    }

    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        unordered_set<string> us = {"+","*","/","-"};
        for(auto it : tokens){
            if(us.find(it) != us.end()){
                int v2 = stoi(s.top());
                s.pop();
                int v1 = stoi(s.top());
                s.pop();
                int ans = calAns(v1,v2,it);
                s.push(to_string(ans));
            }
            else s.push(it);
        }
        int ans = stoi(s.top());
        return ans;
    }
    
};

int main()
{
    std::vector<string> s = {"4","13","5","/","+"} ;
    Solution sol;
    int ans = sol.evalRPN(s);
    
    std::cout<<"ans = " << ans;

    return 0;
}