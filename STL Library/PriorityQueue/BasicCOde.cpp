#include<bits/stdc++.h>
using namespace std;
int main()
{           //max Heap
    priority_queue <int> pq;
    pq.push(1);
    pq.push(89);
    pq.push(3);
    pq.push(4);
    // while (!pq.empty())
    // {
    //     cout<<pq.top()<<" ";
    //     pq.pop();
    // }
                            //MIN Heap
    priority_queue <int , vector<int>, greater<int>> pq2;
    pq2.push(1);
    pq2.push(89);
    pq2.push(3);
    pq2.push(4);
    // while (!pq2.empty())
    // {
    //     cout<<pq2.top()<<" ";
    //     pq2.pop();
    // }
    // cout<<"\n";
    // cout<<pq.size()<<" ";    

    priority_queue <vector<int>> pq3;
    pq3.push({1,2,3});
    pq3.push({78,2,3});
    pq3.push({2,2,3});
    pq3.push({5,2,3});

     while (!pq3.empty())
    {   
        for(auto itr : pq3.top()){
            cout<<itr<<" ";
        }
        cout<<"\n";
        pq3.pop();
    }
    


return 0;
}