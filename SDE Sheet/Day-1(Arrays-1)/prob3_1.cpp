 //Finding the next permutation in for the given array

#include<bits/stdc++.h>
using namespace std;
 

int main()
{
 vector<int> vec = {2,1,4,3};
 next_permutation(vec.begin(), vec.end());
 for(auto num : vec )
    cout<<num<<" ";
return 0;
}