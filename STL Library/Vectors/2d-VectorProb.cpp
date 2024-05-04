
#include<bits/stdc++.h>
using namespace std;

int main()
{
  vector<vector<int>> vec ;
   vector<int> vec2 ;
    vec2.push_back(1);
    vec2.push_back(45);
    vec2.push_back(10);
    vec2.push_back(11);

 
  vec.push_back({1,1,3});
  vec.push_back({2,2,3,2,34});
  vec.push_back({14,100,3});
  vec.push_back({10,2,3});
  vec.push_back({7,200,3});
  
   sort(vec.begin() , vec.end());
   auto itr = vec.begin();
  
  for (int i = 0; i < vec.size(); i++)
  {
    for (int j = 0; j < vec[i].size(); j++)
    {
        cout<<vec[i][j]<<" ";
    }
    
    cout<<endl;
  }
  
return 0;
}