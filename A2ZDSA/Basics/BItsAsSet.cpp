#include<bits/stdc++.h>
using namespace std;


int main()
{
    string  s = "abcde";
    int st = 0;
    for(auto ch : s){
        int mask  = (1<<(ch - 'a'));
        // cout<<mask<<endl;
        st = st | mask; 
    }
    cout<<st<<endl;

    string t = "hemanth";
    for(auto ch : t){
        if((st & (1<<(ch-'a'))) != 0) cout<<ch<<" is present"<<endl;
    }

return 0;
}