#include<iostream>
#include<list>

using namespace std;
int main()
{
    list<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);

    for (auto itr : l1 )
    {
        cout<<(itr)<<" ";
    }
    // Or Else
    // for (auto it = l1.begin(); it != l1.end(); it++)
    // {
        
    // }
    
    
return 0;
}