// Given N houses and M lamps placed on a number line, each at unique positions, 
// find the minimum value of k such that every house receives light from at least one lamp within a distance of k units.

// Input Format

// The first line contains an integer N denoting the number of houses on the number line.

// The second line contains N space-separated integers where Ti denotes the position of the ith house.

// The third line contains an integer M denoting the number of lamps on the number line.

// The fourth line contains M space-separated intergers where I denotes the position of the Ith lamp 

// Output Format

// Print the miniman value required to receive light


// Sample Input
// 3
// -2 2 4
// 2
// -3 0
// Sample Output
// 4


#include<bits/stdc++.h>
using namespace std;


int minLight(int n, vector<int> houses, int m, vector<int> lamps)
{
    sort(houses.begin(), houses.end());
    sort(lamps.begin(), lamps.end());
    int i = 0, j = 0;
    int ans = 0;
    for(int i =0; i < n; i++)
    {
        int minDist = INT_MAX;
        while(j < m && lamps[j] < houses[i])
        {
            j++;
        }
        if(j < m)
        {
            minDist = min(minDist, abs(houses[i] - lamps[j]));
        }
        if(j > 0)
        {
            minDist = min(minDist, abs(houses[i] - lamps[j-1]));
        }
        ans = max(ans, minDist);
    }
    
    
    return ans;
    
}

int main()
{
    // int n;
    // cin >> n;
    // vector<int> houses(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> houses[i];
    // }
    // int m;
    // cin >> m;
    // vector<int> lamps(m);
    // for (int i = 0; i < m; i++)
    // {
    //     cin >> lamps[i];
    // }

    int n = 3;
    vector<int> houses = {-2, 2, 4};
    int m = 2;
    vector<int> lamps = {-3, 0};

    //     int n = 5;
    // vector<int> houses = {1, 5, 10 , 14, 17};
    // int m = 3;
    // vector<int> lamps = {4, 11, 15};


    cout << minLight(n, houses, m, lamps);

    return 0;
}