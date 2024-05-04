// returning a possible pair that sum upto the target

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {4, 7, 11, 4};
    int target = 8;
    vector<pair<int, int>> vec;//using this pair for not to loose the initial index of the number in the array
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
        vec.push_back({nums[i], i});

    sort(vec.begin(), vec.end());

    int l = 0;
    int r = vec.size() - 1;

    while (l < r)
    {
        if ((vec[l].first + vec[r].first) < target)
        {
            l++;
        }
        else if ((vec[l].first + vec[r].first) > target)
        {
            r--;
        }
        else if ((vec[l].first + vec[r].first) == target)
        {

            ans.push_back(vec[l].second);

            ans.push_back(vec[r].second);

            break;
        }
    }
    for(auto num : ans){
        cout<<num<<" ";
    }

    return 0;
}