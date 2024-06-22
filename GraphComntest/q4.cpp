// Apaar is relaxing beside a large pond, while his pet frog Freddy is enjoying in the pond. The pond has N floating leaves, each defined by a x-coordinate and a y-coordinate as viewed from the sky.

// From leaf located at (a, b) frog Freddy can jump:-

// 1) to (a + Z, b + Z) where Z is natural number. Call this direction A.

// 2) to (a + Z, b - Z) where Z is natural number. Call this direction B.

// 3) to (a - Z, b + Z) where Z is natural number. Call this direction C.

// 4) to (a - Z, b - Z) where Z is natural number. Call this direction D.

// Apaar shouts one of the direction and Freddy jumps to the first leaf in chosen direction. If there is no leaf in that direction then Freddy doesn't moves. After Freddy jumps, the leaf Freddy jumps from collapses and sinks forever.

// Freddy starts from first leaf and we also know all the M commands that Apaar shouted in sequence. We want to find out which leaf does Freddy ends up on at the end?

// Constraints

// 1 <= N,M <= 100000.

// X & Y will be in the range of int

// Input

// First line contains two integer N & M representing number of leafs in the pond and number of different commands Apaar shouts.
// Second line contains a string of M characters describing all commands Apaar shouts.
// Next N line contains two integers representing x-coordinate and y-coordinate of ith leaf. Freddy starts from first leaf.

// Output
// Example

// Input
// 7 5
// ACDBB
// 5 6
// 8 9
// 4 13
// 1 10
// 7 4
// 10 9
// 3 7
// Output
// 7 4

// Print final x-coordinate and y-coordinate of Freddy the Frog.

#include <bits/stdc++.h>
using namespace std;

pair<int, int> getFinalPosition(int n, int m, string s, vector<pair<int, int>> &v, vector<pair<int,int>> &visited)
{
    vector<vector<int>> adjList(n+1);
    // create a graph of all the leaves with the given conditions as per the problem statement
    

}

int main()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<pair<int, int>> v(n+1);
    vector<pair<int,int>> visited(n+1, {0,0});
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    pair<int, int> res = getFinalPosition(n, m, s, v, visited);
    cout << res.first << " " << res.second << endl;

    return 0;
}
