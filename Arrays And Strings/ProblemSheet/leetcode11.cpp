#include<bits/stdc++.h>
using namespace std;

int findSpecialInteger(vector<int>& arr) {
    int n = arr.size();
    int len = 1;
    int quarterN = (n/4); 
    int i = 0;
    while(i < n-1){
            
        len = 1;
        while(arr[i] == arr[i+1]){
            len++;
            i++;
        }
        if(len > quarterN) return arr[i];
        i++;
    }
    return -1;
}

int main()
{
    vector<int> arr = {1,2,2,6,6,6,6,7,10};
    cout << findSpecialInteger(arr) << endl;

return 0;
}