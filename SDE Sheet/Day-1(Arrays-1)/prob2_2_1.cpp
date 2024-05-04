// Getting a row from the pascals triangle
#include<bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
long long res = 1;

// calculating nCr:
for (int i = 0; i < r; i++) {
    res = res * (n - i);
    res = res / (i + 1);
}
return res;
}

vector<int> getPascalRow(int n){
    vector<int> ans;    
    for (int i = 0; i < n; i++)
        ans.push_back(nCr(n-1,i));
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> ans = getPascalRow(n);
    for(auto num : ans)
        cout<<num<<" ";
 
return 0;
}