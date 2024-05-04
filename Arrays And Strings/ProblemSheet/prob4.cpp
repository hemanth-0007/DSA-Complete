#include<bits/stdc++.h>
using namespace std;
int main()
{
vector<int> v1 = {2,4,5};
vector<int> v2 = {5,6,4,3,2};
vector<int> sum;
// Getting the sum in the time complexity of O(n+m)
 int carry = 0;
 auto itr1 = v1.begin();
 auto itr2 = v2.begin();
while( itr1 != v1.end() || itr2 != v2.end() || carry != 0){
    int num1 = 0 , num2 = 0;
    if(itr1 != v1.end()) num1 = *(itr1++);
    if(itr2 != v2.end()) num2 = *(itr2++);
    int res = num1 + num2 + carry;
    if(res/10 != 0){
        carry = 1;
        res = res%10;
    }
    else carry = 0;
    
    sum.push_back(res);
     
}
 

//O((m+n)log(m+n))
reverse(sum.begin(), sum.end());

for(auto num : sum){
    cout<<num<<" ";
}


return 0;
}