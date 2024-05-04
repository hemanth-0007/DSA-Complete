#include<bits/stdc++.h>
using namespace std;


bool isUniqueChar(string s){
    unordered_set<int> set;
    for(auto ch : s){
        if(set.find(ch) != set.end()) return false;
        set.insert(ch);
    }
    return true;
}




void helper(int ind,const vector<string>& arr, const string& path, int& result){
    // base code 
    if(isUniqueChar(path)){
        result = max(result, (int)path.size());
    }
    if(ind ==  arr.size() || !isUniqueChar(path)) return;
    // main recursive code
    for(int i = ind ; i < arr.size(); i++){
        helper(i+1, arr, path+arr[i], result);
    }
}


int maxLength(vector<string>& arr) {
    int n = arr.size();
    string path = "";
    int result = 0;
    helper(0, arr,path, result);
    return result;
}


int main()
{
    // vector<string> arr = {"un","iq","ue"};
    vector<string> arr = {"jnfbyktlrqumowxd","mvhgcpxnjzrdei"};
    cout<<maxLength(arr);

return 0;
}