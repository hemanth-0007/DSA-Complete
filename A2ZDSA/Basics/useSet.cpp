#include<bits/stdc++.h>
using namespace std;
int main()
{
    set<int> s;
    s.insert(1);
    s.insert(4);
    s.insert(0);
    s.insert(3);
    s.insert(8);
    // cout<<*(--s.end())<<endl;
    // cout<<*(--s.end())<<endl;
    while(!s.empty()){
        cout<<*(s.begin())<<endl;
        s.erase(s.begin());
    }

return 0;
}