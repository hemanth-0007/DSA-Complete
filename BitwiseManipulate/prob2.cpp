// Solve for 2 numbers that are only repeating once in
// the array

#include <bits/stdc++.h>
using namespace std;

void displayArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void displayMap(map<int, int> &l1) 
{
        map<int, int>::iterator it;
        for (it = l1.begin(); it != l1.end(); it++)
        if(it->second == 1)
                cout << it->first << " " << it->second << endl;
        
}
int main()
{
    int arr[] = {2, 2, 3,10, 4, 4, 5, 1, 1,1,1};
    int n = sizeof(arr) / sizeof(int);

    map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    displayMap(mp);
    

    return 0;
}