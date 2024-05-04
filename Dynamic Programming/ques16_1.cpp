#include<bits/stdc++.h>
using namespace std;
//  generate parenthesis 

string helper(int i , int j, stack<char>& st, vector<int>& result){
    // base conditions


    // main resursive code
    string leftParenthesis = "", rightParenthesis = "";
    if(i > 0){
            st.push('(');
            leftParenthesis += '('  + helper(i-1, j , st, result);
    }
    if(j > 0 && st.top() == '('){
        st.pop();
        rightParenthesis += ')' + helper(i, j-1, st, result);
    }
    return "";
}



vector<string> generateParenthesis(int n) {
    stack<int> st;
    vector<string> result;
    helper(n , n, st, result)
    return result;       
}



int main()
{

return 0;
}