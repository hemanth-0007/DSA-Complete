// Get the majority elemnt in the array that is it occurs 
// greater than n/3 times
// Optimal Approach (instead using 2 variables )

#include<bits/stdc++.h>
using namespace std;
vector<int> majorityElement(vector<int> v) {

     vector<int> temp;
    int n = v.size();
    int cnt1 = 0; // count
    int el1 = INT_MIN; // Element
    int cnt2 = 0; // count
    int el2 = INT_MIN; // Element

    //applying the algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && v[i] != el2) {
            cnt1 = 1;
            el1 = v[i];
        }
        else if (cnt2 == 0 && v[i] != el1){
            cnt2 = 1;
            el2 = v[i];
        }
        else if (el1 == v[i]) cnt1++;
        else if (el2 == v[i]) cnt2++;
        else{
            cnt1--; 
            cnt2--;
        }
    }

    int mini = int(n/3) + 1;
    cnt1 = 0; cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if(v[i] == el1) cnt1++;
        if(v[i] == el2) cnt2++;
    }
    if(cnt1 >= mini) temp.push_back(el1);
    if(cnt2 >= mini) temp.push_back(el2);
    return temp;
    
}
int main()
{
    vector<int> v = {2,3,1,1,1,1,2,2,1};
     vector<int> ans =  majorityElement(v);
     for(auto num: ans) cout<<num<<" ";
return 0;
}