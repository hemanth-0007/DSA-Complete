#include<bits/stdc++.h>
using namespace std;

bool isPossible(int i , int j , int n){
    return (i >=0 && i < n && j >= 0 && j < n);
}


vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
{
    int n = matrix.size();
    vector<int> result;
    // O(N*N) time complexity
    // O(N*N) auxilary space
    for (int j = 0; j < n; j++)
    {
        int x = 0 , y = j;   
        while(isPossible(x ,y ,n))
            result.push_back(matrix[x++][y--]);
    }
    for (int i = 1; i < n; i++)
    {
        int x = i, y = n-1;
        while(isPossible(x ,y ,n))
            result.push_back(matrix[x++][y--]);
    }
    
    return result;
         
}

int main()
{
vector<vector<int>> matrix = {{3 ,2 ,3},
            {4, 5 ,1},
            {7 ,8 ,9}};

vector<int> antiDiagonal = antiDiagonalPattern(matrix);
for(auto num : antiDiagonal) cout<<num<<" ";


return 0;
}