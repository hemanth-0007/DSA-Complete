// Ninja Training problem

#include <bits/stdc++.h>
using namespace std;

int maxPoints(int day , int last , 
vector<vector<int>> tasks ){
    // base condition
    if(day == 0){
        int res = 0;
        for (int i = 0; i <= 2; i++)
        {
            if(i != last){
                res = max(tasks[0][i], res);
            }
        }
        return res;
    }

    int ans = 0;

    for (int i = 0; i <= 2; i++)
        {
            if(i != last){
                int points = tasks[day][i] + maxPoints(day-1, i, tasks);
                ans = max(ans , points);
            }
        }
   return ans;

}

int main()
{
    vector<vector<int>> tasks = {
                                    // {2, 1, 3},
                                    // {3, 4, 6},
                                    {10, 1, 6},
                                    {8, 3, 7}
                                };
      int n = tasks.size();
      int last = 3;

    // Here last represents which task is performed on the prev day 
    // 0 - 0th task 
    // 1 - 1st task 
    // 2 - 2nd task 
      cout<<maxPoints(n-1 , last , tasks);
    
     return 0;
}