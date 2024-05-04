#include <iostream>
#include <iterator>
#include <set>

using namespace std;
int main()
{
    set<int> s1;
    s1.insert(2);
    s1.insert(3);
    s1.insert(3);
    s1.insert(89);
    s1.insert(34);
    s1.insert(1);
    s1.insert(31);

    for (auto itr : s1)
    {
        cout << itr << " ";
    }
    cout<<endl;
    cout<<s1.count(3);//can return 0 or 1 as set contains only unique elements
    return 0;
}