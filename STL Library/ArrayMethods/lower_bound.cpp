#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {1,2,3,7};
    for(int i = 0; i < v.size(); i++) cout << i << " ";
    cout << endl;
    for(auto i : v) cout << i << " ";
    cout << endl;
    auto it = v.begin();
    cout<<*v.end()<<endl;
    it = lower_bound(v.begin(), v.end(), 5);
    // cout<<it<< endl;
    // print index of the element
    // print the element
    cout << *it << endl;
    cout << it - v.begin() << endl;
return 0;
}