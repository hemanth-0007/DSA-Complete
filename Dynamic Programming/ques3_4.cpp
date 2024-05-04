//maximun sum of the non-adjacent elemnts from  a
// subsequence in an array 
// space optimising  the solution 
#include<bits/stdc++.h>
using namespace std;
 

int main()
{
vector<int> a = {2,1,4, 9};
int n = a.size();
 

int prev = a[0];
int prev2 = 0;
int curi = 0;

// TC - O(N) and sc - O(1)
 for (int i = 1; i < n; i++)
 {
    int pick = a[i] ;
    // to exlude the edge case of negative index of the array dp
    if(i > 1)
        pick += prev2;

    int notPick = prev;
    curi = max(pick , notPick);
    prev2 = prev;
    prev = curi;
 }
 // curi or prev will give u the correct ans
 cout<<prev<<endl;
 cout<<curi;
 
 
return 0;
}