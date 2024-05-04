#include<bits/stdc++.h>
using namespace std;

bool isDuplicateParenthesis(string s){

    int n = s.size();
    stack<char> st;
    int duplicate = 0;
    for(auto ch : s){
        if(ch == ')'){
            char stackTop  = st.top();
            st.pop();
            int elementsCount = 0;
            // cout<<"Entering the While loop"<<stackTop<<endl;
            while(stackTop != '('){
                // cout<<"In while loop"<<stackTop<<endl;
                // cout<<elementsCount<<" "<<stackTop<<endl;
                elementsCount++;
                stackTop = st.top();
                st.pop();
            }
            cout<<elementsCount<<endl;
            if(elementsCount <= 1) return true;
        }
        else st.push(ch);
    }
    
    return false;
}






int main()
{
    string s = "((a+b))";
    // string s = "(a+((b - d)))";
    cout<<isDuplicateParenthesis(s)<<endl;

return 0;
}