#include<bits/stdc++.h>
using namespace std;
//Better solution than prev one hwich is of tc - O(mn)
// we can we two independent arrays instead row , col
 
 // here tc - O(2* m * n)
 // sc - O(m+n)
void rowColZero(vector<vector<int>> &vec, 
vector<int> &row, vector<int> &col){
    
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            if(vec[i][j] == 0){
                row[j] = 1;
                col[i] = 1;
            }
        }
        
    }
    
     
     for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
             if(row[j] == 1 || col[i] == 1){
                vec[i][j] = 0;
             }
        }
        
    }

}


int main()
{
vector<vector<int>> vec = { {0,12,3},
                            {1,2,4},
                            {9,76,0},
                            {6,56,1}
                            };
                      
    int n = vec.size();
    int m = vec[0].size();
    vector<int> row(m, -1);
    vector<int> col(n, -1);


    rowColZero(vec , row , col);
 

  for(auto itr : vec){
      for(auto it : itr){
          cout<<it<<" ";  
      }
      cout<<endl;
  }
 
return 0;
}