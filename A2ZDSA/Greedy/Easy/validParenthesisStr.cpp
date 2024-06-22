#include <bits/stdc++.h>
using namespace std;
 
 bool checkValidString(string s)
{
     int n = s.size();
     stack<int> open, ast;
     for (int i = 0; i < n; i++)
     {
        if(s[i]  == '(') open.push(i);
        else if(s[i] == '*')ast.push(i);
        else{
            if(!open.empty()) open.pop();
            else if(!ast.empty()) ast.pop();
            else return false;
        }    
     }
     while(!open.empty() && !ast.empty()){
        if(open.top() > ast.top()) return false;
        open.pop();
        ast.pop();
     }
     if(open.empty()) return true;
     return false;
}



bool checkValidStringOp(string s)
{
     int n = s.size();
     int openCnt = 0, closeCnt = 0;
     for (int i = 0; i < n; i++)
     {
        if(s[i] == '(' || s[i] == '*') openCnt++;
        else openCnt--;

        if(s[n-1-i] == ')' || s[i] == '*') closeCnt++;
        else closeCnt--;

        if(openCnt<0 || closeCnt < 0) return false;
     }
    return true;
}

int main()
{
    string  s = "(*)))";
    cout<<checkValidString(s);

    return 0;
}