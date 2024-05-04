#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    vector<int> score = {10,3,8,9,4};
    vector<int> temp(score);
    int n = score.size();
    vector<string> ans;
    sort(temp.begin(), temp.end(), greater<int>());
    map<int ,int> mpp;
    // for(auto num : temp) cout<<num<<" ";
    int i = 0;
    for(auto num : temp){
         mpp[num] = i+1;
         i++;
    }

    for(auto num : score){
        
       if(mpp[num] == 1)
        ans.push_back("Gold Medal"); 
       
       if(mpp[num] == 2)
        ans.push_back("Silver Medal"); 
       
       if(mpp[num] == 3)
        ans.push_back("Bronze Medal"); 
         
       if(mpp[num]>3) ans.push_back(to_string(mpp[num]));
      
        
    }
        
    for(auto sr : ans) cout<<sr<<" ";
    cout<<"\n"<<ans.size();

    return 0;
}