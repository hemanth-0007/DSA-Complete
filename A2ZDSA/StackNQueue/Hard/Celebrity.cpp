#include<bits/stdc++.h>
using namespace std;


int celebrity(vector<vector<int> >& M, int n) 
    {
         
        stack<int>st;
        //step 1:push all person in stack
        for(int i=0;i<n;i++) st.push(i);
         
        //step 2:use discard method to get aperson who might be celebrity
        while(st.size()!=1){
            int a=st.top(); st.pop();
            int b=st.top(); st.pop();
            if(M[a][b])  st.push(b);
            else st.push(a);
        }
        //step 3:check this single remaining person instack whether he is celebrity or not
        int t=st.top();
        int row=0,col=0;
        for(int i=0;i<n;i++){
            row+=M[t][i];
            col+=M[i][t];
        }
        if(row==0 && col==(n-1)){
            return t;
        }
        else{
            return -1;
        }
}

int main()
{

return 0;
}