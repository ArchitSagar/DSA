// MIN STACK



#include <bits/stdc++.h>

using namespace std;


class MinStack {
    stack<long long> st;
    long long mini;
public:
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini = val;
        }
        else if(val < mini){
            st.push(2LL*val - mini);
            mini = val;
        }
        else{
            st.push(val);
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long el = st.top();
        st.pop();
        if(el < mini){
            mini = 2LL*mini - el;
        }

    }
    
    int top() {
        if(st.empty()) return -1;
        long long el = st.top();
        if(el < mini) return mini;
        return el;
    }
    
    int getMin() {
        return mini;
        
    }
};


int main(){
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl; // return -3
    minStack.pop();
    cout << minStack.top() << endl;    // return 0
    cout << minStack.getMin() << endl; // return -2
}
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */