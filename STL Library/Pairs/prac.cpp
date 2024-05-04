#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<int,pair<int,int>> mp;
   mp[4] = {1,1};
   mp[5] = {1,3};
   mp[12] = {1,1};
   mp[15] = {1,14};
   mp[6] = {1,87};
   mp[9] = {1,43};
   
    auto itr = mp.begin();
    // cout<<(*itr).first.first;
    // for(auto it : mp){
    //     cout<<it.first.first<<" ";
    // }
    auto ptr = mp.find(12);
      mp.erase(ptr);
 
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        cout<<i->first<<" ";
    }
    

return 0;
}