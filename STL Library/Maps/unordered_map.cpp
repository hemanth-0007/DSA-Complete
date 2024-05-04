#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int, int> umap;
    vector<int> vec1 = {1, 1, 2, 2, 2, 4, 5};
    for(auto num : vec1) umap[num]++;
    for(auto num : umap) cout<<num.first<<" "<<num.second<<endl;
return 0;
}