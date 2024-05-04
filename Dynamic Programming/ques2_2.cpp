// ques 2 follow up ,
// such that frog can take upto k steps 
 

#include<bits/stdc++.h>
using namespace std;

 

int minEnergy(vector<int> energy ,int ind, int k){
        if(ind == 0){
            return 0;
        }
        int minStep = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if((ind - j) >= 0){
                int step = minEnergy(energy ,ind-j, k) + abs(energy[ind] - energy[ind-j]);
                minStep = min(step , minStep);
            }
            
        }
 
        return minStep;

}


int main()
{
int n = 4;
int k = 2;
vector<int> energy = {10, 20 , 10, 40};
cout<<minEnergy(energy , n-1, k)<<endl;
return 0;
}