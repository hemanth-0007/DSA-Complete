// Get the majority elemnt in the array that is it occurs 
// greater than n/2 times
// Optimal Approach

#include<bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();
    int cnt = 0; // count
    int el; // Element

    //applying the algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i]) cnt++;
        else cnt--;
    }

    //checking if the stored element
    // is the majority element:
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el) cnt1++;
    }

    if (cnt1 > (n / 2)) return el;
    return -1;
}
int main()
{
    vector<int> v = {2,2,1,1,1,1,2,2,1};
    cout<<majorityElement(v);
return 0;
}