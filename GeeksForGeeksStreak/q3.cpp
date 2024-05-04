#include<bits/stdc++.h>
using namespace std;

// 3 by 3 matrix determinent

int cofactor(vector<vector<int>>& matrix, int i , int j){
    cout<<matrix[(i+1)%3][(j+1)%3]<<" "<<matrix[(i+2)%3][(j+2)%3]<<" "<<matrix[(i+2)%3][(j+1)%3]<<" "<<matrix[(i+1)%3][(j+2)%3]<<endl;

    return (matrix[(i+1)%3][(j+1)%3]*matrix[(i+2)%3][(j+2)%3] 
    - matrix[(i+2)%3][(j+1)%3]*matrix[(i+1)%3][(j+2)%3]);
}



int determinent(vector<vector<int>>& matrix){
    int ans = 0;
    for (int j = 0; j < 3; j++){
        int temp = matrix[0][j]*cofactor(matrix,0, j);
        ans += temp;
        // cout<<temp<<endl;
    }
        
    return ans;
}


vector<vector<int>> minor(const vector<vector<int>>& matrix, int row , int col){
    int n = matrix.size();
    vector<vector<int>> result(n - 1, vector<int>(n - 1));

    for (int i = 0, r = 0; i < n; ++i) {
        if (i == row) continue; // Skip the specified row
        for (int j = 0, c = 0; j < n; ++j) {
            if (j == col) continue; // Skip the specified column
            result[r][c] = matrix[i][j];
            ++c;
        }
        ++r;
    }

    return result;
}

// for a n by n matrix
int nthDeterminent(const vector<vector<int>>& matrix){
    
    int n = matrix.size();
    int ans = 0;
    if(n == 1){
        return matrix[0][0];
    }
    else{
        for(int j = 0 ; j < n ;j++)
            ans += ((j % 2 == 0) ? 1 : -1) * matrix[0][j] * nthDeterminent(minor(matrix, 0 , j));      
    }
    return ans;
}





int main()
{
    // vector<vector<int>> matrix = {{1,2,3}, 
    //                               {4,5,6},
    //                               {7,8,9}};
    // cout<<determinent(matrix);
    // cout<<cofactor(matrix, 1, 0);

    vector<vector<int>> matrix =  {{1, 4, 6, 1}, {4, 7, 4, 8}, {6, 7, 2, 9}, {9, 1, 2, 1}};
    // -256
    cout<<nthDeterminent(matrix);

return 0;
}