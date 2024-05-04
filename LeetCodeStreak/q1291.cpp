#include<bits/stdc++.h>
using namespace std;

vector<int> sequential_digits(int low, int high){
    string s = "123456789";
    vector<int> ans;
    for(int i=0; i<s.size(); i++){
        for(int j=i+1; j<s.size(); j++){
            int num = stoi(s.substr(i, j-i+1));
            if(num>=low && num<=high){
                ans.push_back(num);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}



int main()
{

return 0;
}