#include<bits/stdc++.h>
using namespace std;



int minimizeTheDifference(vector<vector<int>>& mat, int target) {
    bitset<4901> arr, validSum, zero(0);
    arr[0] = 1;
    validSum[0] = 1;
    for (int i = 0; i < mat.size(); i++)
    {
        arr = validSum;
        validSum = (validSum & zero);
        for (int j = 0; j < mat[0].size(); j++)
        {
            arr = (arr << mat[i][j]);
            validSum = (arr | validSum);
            arr = (arr >> mat[i][j]);
        }
    }
//    for (int i = 0; i < 20; i++)
//    {
//      cout<<arr[i]<<endl;
//    }
    // cout<<validSum[12]<<endl;
    // cout<<validSum[13]<<endl;

    int ans = 1e9;
    for(int i = 0; i <= 4900; i++){
        if(validSum[i] == 1) ans = min(ans, abs(target - i));
    }
    return ans;
}


int main()
{
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    int target = 13;
    cout<<minimizeTheDifference(mat, target)<<endl;

return 0;
}