#include<bits/stdc++.h>
using namespace std;
// winner of an election





int main()
{
    map<string, int> mp;
    int n = 13;
    string arr[] = {"john","johnny","jackie","johnny","john", "jackie","jamie","jamie","john","johnny","jamie","johnny","john"};
    // iterate over the array of strings arr
    // cout<<"size of arr: "<<sizeof(arr)/sizeof(arr[0])<<endl;
    for (int i = 0; i < n; i++)
    {
        // auto it = mp.find(arr[i]) ;
        // if(it != mp.end() && it->first == arr[i])  mp[arr[i]]++;
        
        mp[arr[i]]++;
    }
    for(auto it : mp) cout<<it.first<<" "<<it.second<<endl;
    int max_votes = 0;
    string winner = "";
    for(auto it : mp){
        if(it.second > max_votes){
            max_votes = it.second;
            winner = it.first;
        }
        else if(it.second == max_votes && winner > it.first){
            winner = it.first;
        }
        cout<<winner<<" "<<max_votes<<endl;
    }
    cout<<winner<<endl;
    
    

return 0;
}