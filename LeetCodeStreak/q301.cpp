#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<pair<int,int>> st;
    int min_value = 1e9;
    MinStack() {
        
    }
    
    void push(int val) {
        
            min_value = min(min_value, st.top().second);
            st.push({val,min_value});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        if (!st.empty()) {
            return st.top().first;
        }
        return -1; // or throw an exception
    }
    
    int getMin() {
        if (!st.empty()) {
            return st.top().second;
        }
        return -1; // or throw an exception
    }
};


int main()
{

return 0;
}