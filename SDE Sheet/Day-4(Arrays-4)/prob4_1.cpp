
#include<bits/stdc++.h>
using namespace std;

int lengthofLongestSubstring(string s){

    set<char> st;
    int maxi = -1e9;
    int len = 0 , n = s.length();
// O(nlogn)
    for (int i = 0; i < n; i++)
    {
        auto itr = st.find(s[i]);
        if(itr != st.end()){
            maxi = max(maxi , len);
            len = 1;
            st.clear();
            st.insert(s[i]);
        }
        else{
            len++;
            maxi = max(maxi , len);
            st.insert(s[i]);
        }
    }
    
    return maxi;
    

}

int main()
{
string s = "ababababcxvq";
cout<<lengthofLongestSubstring(s);
return 0;
}