#include<bits/stdc++.h>
using namespace std;

void displayVector(vector<vector<int>> &v){

//    for(auto itr = v.begin(); itr != v.end() ; itr++){

//         for(auto itr2 = itr->begin(); itr2 != itr->end(); itr2++){
//             cout<<(*itr2)<<" ";
//         }
//         cout<<endl;
        
//    }

   for(int i = 0 ; i < v.size(); i++){
        for (int j = 0; j < v[i].size(); j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
        
   }
}
 
int main()
{
    vector<vector<int>> vec(2,vector<int>(2,0));// initialising the size if the vector 
    displayVector(vec);
    int num = 10;
     for (auto i = vec.begin(); i != vec.end(); i++) {
        // Vector to store column elements
        vector<int> v1;
  
        for (auto j = i->begin(); j != i->end() ; j++) {
            v1.insert(j,num);
            num += 5;
        }
  
        // Pushing back above 1D vector
        // to create the 2D vector
        vec.insert(i,v1);
    }
     displayVector(vec);
    
return 0;
}