#include<bits/stdc++.h>
using namespace std;

int getNewX(vector<vector<int>>& land, int i, int j){
    int n = land.size(), m = land[0].size();
    for (int x = i; x < n; x++)
        if(land[x][j] != 1) return x - 1;
    return n-1;
}

int getNewY(vector<vector<int>>& land, int i, int j){
    int n = land.size(), m = land[0].size();
    for (int y = j; y < m; y++)
        if(land[i][y] != 1) return y - 1;
    return m-1;
}


void make_zero(vector<vector<int>> & land, int start_x, int start_y, 
int end_x , int end_y){
    int n = land.size(), m = land[0].size();
    for (int i = start_x; i <= end_x; i++)
    {
        for (int j = start_y; j <= end_y; j++)
        {
            land[i][j] = 0;
        }
        
    }
    
}


void print_land(vector<vector<int>>& land){

    cout<<"printing land: "<<endl;
    for(auto v : land){
        for(auto num : v){
            cout<<num<<" ";
        }
        cout<<endl;
    }

}

vector<vector<int>> findFarmland(vector<vector<int>>& land) {
    int n = land.size(), m = land[0].size();
    vector<vector<int>> res;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<i<<" "<<j<<endl;
            if(land[i][j] == 1){
                int old_i = i, old_j = j;
                i = getNewX(land, i , j);
                j = getNewY(land, i , j);
                make_zero(land, old_i, old_j , i ,j);
                res.push_back({old_i, old_j, i, j});
                // if(i < n-1) i = i+1;
                print_land(land);
                i = old_i;
                if(j < m-1) j = j+1;
            }
        }
    }
    return res;     
}

int main()
{
    // vector<vector<int>> land = {
    //     {1,0,0},
    //     {0,1,1},
    //     {0,1,1},
    // };
    vector<vector<int>> land = {{1,1,0,0,0,1},{1,1,0,0,0,0}};
    vector<vector<int>> res = findFarmland(land);
    for(auto v : res){
        for(auto num : v){
            cout<<num<<" ";
        }
        cout<<endl;
    }

    return 0;
}
