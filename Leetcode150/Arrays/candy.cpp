#include<bits/stdc++.h>
using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> candy(n , 1);
    int candies = n;
    for(int i = 0 ; i < n ; i++){
        if(i == 0){
            if(ratings[i+1] < ratings[i] ) candy[i] += 1;
        }
        if(i == n-1){
            if(ratings[i-1] < ratings[i]) candy[i] += 1;
        }
        
    }
}

int main()
{

return 0;
}