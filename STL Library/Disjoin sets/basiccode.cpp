#include<bits/stdc++.h>
using namespace std;
class DSU
{
public:
     int *parent;
    int *rank;
    DSU(int v)
    {
        parent = new int[v];
        rank = new int[v];
        for (int i = 0; i < v; i++)
        {
            parent[i] = INT16_MAX;
            rank[i] = 1;
        }
    }
    void make_set(int x){
        parent[x] = -1;
    }
    int find(int i)
    {
        if (parent[i] == -1)
        {
            return i;
        }
        else
        {
            parent[i] = find(parent[i]);
            return parent[i];
        }
    }

    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);
        if (rank[s1] > rank[s2])
            parent[s2] = s1;
        else if (rank[s1] < rank[s2])
            parent[s1] = s2;
        else
            parent[s2] = s1;
        rank[s1]++;
    }
     
};

 


int main()
{
    DSU s(100);
    s.make_set(2);
    s.make_set(3);
    s.make_set(4);
    s.make_set(8);
 
    s.unite(2,4);
    s.unite(3,8);
    s.unite(3,4);
    cout<<s.find(2)<<endl;
    cout<<s.find(4)<<endl;
    cout<<s.find(8)<<endl;
    cout<<s.find(3)<<endl;
    cout<<s.rank[2]<<endl;
    cout<<s.rank[4]<<endl;
    cout<<s.rank[8]<<endl;
    cout<<s.rank[3]<<endl;
    

return 0;
}