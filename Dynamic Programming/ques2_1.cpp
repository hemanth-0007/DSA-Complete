// Given an array of energies of steps from 0 to n-1
// a frog needs ot go from 0 to n - 1 we neeed to find out the 
// path for minimal energy req.
//(DP --> lec 3)

#include<bits/stdc++.h>
using namespace std;

int mod(int n){
    return n>0? n : (-1)*n;
}

 

int minEnergy(vector<int> energy ,int ind){
        if(ind == 0){
            return 0;
        }
        int secondStep = INT_MAX;
        int firstStep = minEnergy(energy ,ind-1) + abs(energy[ind] - energy[ind-1]);
        if(ind > 1)
         secondStep = minEnergy(energy, ind - 2) + abs(energy[ind] - energy[ind-2]);
     
        
        return min(firstStep, secondStep);

}


int main()
{
int n = 4;
vector<int> energy = {10, 20 , 10, 40};
cout<<minEnergy(energy , n-1)<<endl;
return 0;
}