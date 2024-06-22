#include<bits/stdc++.h>
using namespace std;
 string oddEven(string s) {
        unordered_map<char,int> mp;
        int n = s.size();
        for(auto ch : s) mp[ch]++;
        int cnt = 0;
        for(auto it : mp){
            if(((it.first -'a' + 1)%2) != 0 && (it.second%2) != 0){
                cout<<it.first<<" "<<it.second<<endl;
                cnt++;
            }
            else if(((it.first -'a' + 1)%2) == 0 && (it.second%2) == 0) {
                cout<<it.first<<" "<<it.second<<endl;
                cnt++;
            }
        }
        return cnt%2 != 0 ? "ODD" : "EVEN";
}
int main()
{
    cout<<oddEven("abbbcc");

return 0;
}