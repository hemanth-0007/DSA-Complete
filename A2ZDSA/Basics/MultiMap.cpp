#include<bits/stdc++.h>
using namespace std;
int main()
{
    multimap<int,int> mp;
    mp.insert({1,2});
    mp.insert({1,3});
    mp.insert({2,3});
    mp.insert({4,5});
    mp.insert({3,2});
    // for(auto it : mp ) cout<<it.first<<" "<<it.second<<endl;
   auto itr = mp.find(1);
   while(itr->first == 1 && itr != mp.end()){
    cout<<itr->first<<" "<<itr->second<<endl;
    itr++;
   }
return 0;
}