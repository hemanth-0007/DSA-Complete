#include<bits/stdc++.h>
using namespace std;
int main()
{
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_back(4);
    for(auto num : dq) cout<<num<<" ";
    cout<<endl;
    dq.push_front(0);
    for(auto num : dq) cout<<num<<" ";
    cout<<endl;
    dq.pop_back();
    for(auto num : dq) cout<<num<<" ";
    cout<<endl;
    

return 0;
}