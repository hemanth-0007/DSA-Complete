// Longest consecutive sequence in an array
// Optimal solution using the set data structure
#include<bits/stdc++.h>
using namespace std;

int longestConsec(vector<int> &nums){
  set<int> st;
  for(auto num : nums)
      st.insert(num);
  int longestStreak = 0;
  

  for(auto num : nums){
    if(!st.count(num - 1)){
      int currentNum = num;
      int currentStreak = 0;
      while (st.count(currentNum + 1))
      {
        currentStreak++;
        currentNum++;
      }
      longestStreak = max(longestStreak, currentStreak);
      
    }
  }
  return longestStreak;
}



int main()
{
 vector<int> v = {1,1,1,1,2,2,2,2,3,4,5,6,7,99,100};

 cout<<longestConsec(v);

return 0;
}