#include<bits/stdc++.h>
using namespace std;

// A research institute has decided to allocate grants for their N research teams
//  based on their performance metrics. 
// The institute has a total budget of B dollars for these grants. 
// However, to promote fairness and motivation, 
// the institute has decided that no team shall receive less funding than a team with a lower performance score. 
// Each team has been given a performance score, 
// and the grants must be allocated such that higher-scoring teams receive equal or more funding than the lower-scoring ones, 
// while ensuring that the total allocated budget does not exceed B.

// Given the constraint of the total budget, 
// your task is to find the minimum possible grant amount that can be allocated to the lowest-scoring team,
//  ensuring that all constraints are satisfied and the total spending does not exceed the budget B.

// Input Format

// The first line contains two space-separated integers N and B,
//  where N is the number of research teams and B is the total budget. 
// The second line contains N space-separated Intergers,
// representing the performance scores of the N teams

// Output Format

// Display a single Integer representing the minimum possible grant amount that can be allocated to the lowest-scoring team, insuring that the allocation is fair and under the budget.


// sample input
// 4 100
// 20 30 40 50
// sample output
// 10

int minGrant(int n, int b, vector<int> scores)
{
    sort(scores.begin(), scores.end());
    int minGrant = 0;
    for (int i = 0; i < n; i++)
    {
        int curGrant = b / (n - i);
        if (curGrant < scores[i])
        {
            return curGrant;
        }
        minGrant = curGrant;
        b -= scores[i];
    }
    return minGrant;
}

int main()
{
    // int n , b;
    // cin >> n >> b;
    // vector<int> scores(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> scores[i];
    // }

    int n = 4, b = 100;
    vector<int> scores = {20, 30, 40, 50};

    // int n = 3, b = 200;
    // vector<int> scores = {8,8, 8};

    cout << minGrant(n, b, scores);

return 0;
}