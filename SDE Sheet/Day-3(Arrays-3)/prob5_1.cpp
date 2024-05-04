// Longest consecutive sequence in an array
#include<bits/stdc++.h>
using namespace std;

int longestConsec(vector<int> &v, int n){
  if(n==0) return 0;
  int maxi = -1e9;
  int prev = v[0];
  int length = 1;

  for (int i = 1; i < n; i++)
  {
    if(v[i] == prev + 1){
      prev = v[i];
      length++;
      maxi = max(maxi, length);
      continue;
    }
    else{
      prev = v[i];
      length = 1;
    }
     
  }
  if(maxi == -1e9) return 1;
  return maxi;
}



int main()
{
 vector<int> v = {1,1,1,1,2,2,2,2,3,4,5,6,7,99,100};
 int n = v.size();
 cout<<longestConsec(v,n);

return 0;
}