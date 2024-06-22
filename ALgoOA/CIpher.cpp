#include<bits/stdc++.h>
using namespace std;
int main(){
    string key, msg, ans;
    cin>>key>>msg;
    unordered_set<char> st;
    vector<int> arr(26, 0);
    int i = 0;
    for(; i < key.size(); i++){
        arr[i] = key[i] - 'a';
        st.insert(key[i]);
    }
    int j = 0;
    for(; i < 26; i++){
        while(j < 26 && st.find(j + 'a') != st.end()) j++;
        arr[i] = j;
        j++;
    }
    //  for(i = 0; i < 26; i++) cout<<char(arr[i] + 'a')<<" ";
    for(auto ch : msg) ans += arr[ch - 'a'] + 'a';
    cout<<ans<<endl;
    return 0;
}

// c d f g h i j k l m n o p q t u v w x y