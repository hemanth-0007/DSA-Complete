#include<bits/stdc++.h>
using namespace std;

vector<int> findTwoElement(vector<int> arr, int n) {
    long long int sum  =0, totalSum = (n*(n+1))/2;;
    for(auto num : arr) sum += num;
    long long int diff = sum - totalSum;

    // we need to find the sum of them twoSum
    long long int squareSum = 0 , totalSqaureSum = (n*(n+1)*(2*n+1))/6;
    for(auto num : arr) squareSum += num*num;
    long long int twoSum = (squareSum - totalSqaureSum)/diff;

    long long int repNum = (diff + twoSum)/2;
    long long int missNum = (twoSum - diff)/2;
    return {int(repNum), int(missNum)};
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    vector<int> res =  findTwoElement(arr, n);
    cout<<res[0]<<' '<<res[1];
return 0;
}