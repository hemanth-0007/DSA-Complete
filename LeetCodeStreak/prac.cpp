#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i = 0, n = 5;
    vector<int> arr = {1,2, 2, 3, 4};
    do
    {
        cout<<arr[i]<<endl;
    } while (i < n && arr[i + 1] == arr[i++]);
    
return 0;
}