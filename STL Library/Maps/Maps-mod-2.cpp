/*
Coping elements form one map to other
*/
#include <iostream>
#include <map>
using namespace std;

void displayMap(map<int, int> &l1)
{
        map<int, int>::iterator it;
        for (it = l1.begin(); it != l1.end(); it++)
                cout << it->first << " " << it->second << endl;
}

int main()
{
        map<int, int> mp, m1;
        mp.insert({1, 3});
        mp.insert({8, 0});
        mp.insert({5, 6});
      

        auto it = mp.begin();  // points to the starting address
        auto itr = mp.end();   // points to the ending address

        m1.insert(it, itr);    // here it gives the starting address of the map while 
                               //itr gives you the ending address of the map 
                                //and inserts the elements from the starting to 
                                // ending address
        displayMap(m1);
        displayMap(mp);
                                //or else we can direclty assign the values
        map <int, int> m2(mp.begin(),mp.end());
        displayMap(m2);
        return 0;
}