#include<bits/stdc++.h>
using namespace std;

vector<int> f(multimap<int,int> &mp, int k){
    vector<int> ans;
    int i = 0;
    for(auto it : mp){
        ans.push_back(it.second);
        i++;
        if(i == k) return ans;
    }

    return ans;
}

void print_multimap(multimap<int,int> &mp){
    cout<<"Printing multimap"<<endl;
    for(auto it : mp){
        cout<<it.first<<" "<<it.second<<endl;
    }
}


// vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
//     // code here
//     vector<vector<int>> result(N);
//     map<int,int> mp;
//     multimap<int,int> mlmp;
//     for(int i = 0; i < N; i++){
//         mp[arr[i]]++;
//     }
//     for(auto it : mp){
//         mlmp.insert({it.second, it.first});
//     }
//     print_multimap(mlmp);
//     return result;
// }

void printVec(vector<int> &v){
    for(auto num: v){
        cout<<num<<" ";
    }
    cout<<endl;
}


vector<vector<int>> kTop(vector<int>& a, int N, int K) {
        // code here
        vector<vector<int>> final_ans;
        vector<int> top(K + 1, 0);
        unordered_map<int, int> freq;
        // cout<<"frequnecy map"<<freq[1]<<endl;
    
        for (int m = 0; m < N; ++m) {
            freq[a[m]] += 1;
    
            top[K] = a[m];
            int i = find(top.begin(), top.end(), a[m]) - top.begin() - 1;
            // cout<<i<<endl;
            // inserting the element at correct position
            while (i >= 0) {
                if (freq[top[i]] < freq[top[i + 1]]) {
                    swap(top[i], top[i + 1]);
                } else if ((freq[top[i]] == freq[top[i + 1]]) && (top[i] > top[i + 1])) {
                    swap(top[i], top[i + 1]);
                } else {
                    break;
                }
                i -= 1;
            }
            // printVec(top);
    
            i = 0;
            vector<int> ans;
            while (i < K && top[i] != 0) {
                ans.push_back(top[i]);
                i += 1;
            }
    
            final_ans.push_back(ans);
        }
    
        return final_ans;
}





int main()
{
    // vector<int> nums = {2, 1, 1, 1, 2};
    vector<int> nums =  {5, 2, 1, 3, 2};
    printVec(nums);
    int K = 4;
    vector<vector<int>> result = kTop(nums, nums.size(), K);
    for(auto v: result){
        for(auto num: v){
            cout<<num<<" ";
        }
        cout<<endl;
    }

return 0;
}