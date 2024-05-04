// Trams Problem Hacker Earth

#include<bits/stdc++.h>
using namespace std;

long long solve (int N, int start, 
int finish, vector<int> Ticket_cost) {
    
   start = start -1;finish = finish -1;
   int clck = 0 , sum = 0;
   for(int i = 0; i<N ; i++) sum += Ticket_cost[i];
   int i = start;
   while (i != finish){
    clck += Ticket_cost[i];
    i = (i+1)%N;
   }
    
   return min(clck , sum - clck);
}

int main()
{
    vector<int> vec = {1,2,2,4};
    int n = vec.size();
    cout<<solve(n,4,3,vec);

return 0;
}
