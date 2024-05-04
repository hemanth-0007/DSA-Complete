#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s , int start , int end){
        while (start <= end)
        {
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
        
}
 

void func(int ind , string s , vector<string> path , 
 vector<vector<string>> &ans){
    if(ind == s.size()){
        ans.push_back(path);
        return;
    }

    for (int i = ind; i < s.size(); i++)
    {
        if(isPalindrome(s, ind , i)){
            path.push_back(s.substr(ind,i - ind + 1));
            func(i +1  ,s, path , ans);
            path.pop_back();
        } 
    }
    
 }


vector<vector<string>> getPartionPalindrome(string s){
    vector<vector<string>> ans;
    vector<string> path;
    func(0, s , path , ans);   
    return ans;
}


int main()
{
string s = "aabb";
vector<vector<string>> v = getPartionPalindrome(s);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout<<v[i][j]<<"  ";
        }
        cout<<endl;
        
    }
    
return 0;
}