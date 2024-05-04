// Sprinklr robots problem 
// consider a situation that robot are in an horizontal line 
// ans moving left and right 
// if two robots collide with same energy none is left 
// if s1 , s2 got hit and s1 > s2 then robot moves with energy s1-s2 in the same direction

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> getRes(vector<vector<int>> grid, int n){

        vector<vector<int>> res;
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            int cur_dir = grid[i][1];
            int cur_hlt = grid[i][0];
            if( cur_dir == 0 && st.empty()){
                cout<<"dir is 0 and st empty so include"<<endl;
                 res.push_back({cur_hlt , cur_dir});
            }
            if(cur_dir == 1){
                cout<<"dir is 1 so push into stack"<<endl;
                st.push(cur_hlt);
            }
            if(cur_dir == 0 && (!st.empty())){
                cout<<"dir is 0 stack stack is not empty"<<endl;
                while ((!st.empty()) && cur_dir == 0)
                {
                    int prev_hlt = st.top();
                    st.pop();
                    if(prev_hlt > cur_hlt){
                        cur_hlt = prev_hlt - cur_hlt;
                        cur_dir = 1;
                        st.push(cur_hlt);
                   
                    }
                    else if(prev_hlt == cur_hlt){
                        cur_hlt = 0;
                        break;
                    }
                    else if(prev_hlt < cur_hlt){
                        cur_hlt = cur_hlt - prev_hlt ;
                        cur_dir = 0;
                    }
                 
                }
                if(st.empty() && cur_hlt != 0) res.push_back({cur_hlt,0});
                
            }
            
        }
        
    while (!st.empty())
    {
        int hlt = st.top();
        st.pop();
        res.push_back({hlt,1});
    }

    return res;
    
}

void printVec(vector<vector<int>>& res){

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
int main()
{
 
    vector<vector<int>> grid;
    grid = {
        {12,0},
        {2,0},
        {10,0},
        {20,0},
        {6,0}
    };

     int n = grid.size();
    //  printVec(grid);
     vector<vector<int>> res = getRes(grid, n);
     printVec(res);


return 0;
}