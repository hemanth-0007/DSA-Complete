#include<bits/stdc++.h>
using namespace std;

// descending of the first and ascnding of the second 

bool comparator(pair<int,int> p1, pair<int, int> p2){
    if(p1.first > p2.first) return true;
    if(p1.first < p2.first) return false;
    if(p1.second < p2.second) return true;
    return false;
}




int main()
{
    pair<int, int> arr[] = {{8, 4}, {5, 2}, {8, 6}};
    int n = sizeof(arr)/sizeof(pair<int,int>);
    cout<<n<<endl;
    sort(arr , arr + n , comparator);
    // sort(arr , arr + n , greater<pair<int,int>>());
    for (int i = 0; i < n; i++)
        cout<<"("<<arr[i].first<<" "<<arr[i].second<<")"<<" ";
    
    return 0;
}