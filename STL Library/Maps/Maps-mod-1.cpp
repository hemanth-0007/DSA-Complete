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
        map<int, int> l1;// defining a map
        // assigning key value pairs to the map
        l1[1] = 3;
        l1[2] = 4;
        l1[4] = 90;


        //Erase function 
        map<int, int>::iterator it;
        it = l1.find(4);
                                  // or can be like l1.begin() where the first element will get deleted
        l1.erase(it);             // give the iterator position of the element
        displayMap(l1);



        cout<<l1.size()<<endl;
        cout<<l1.max_size()<<endl;
        l1.clear();             // clears all the elements in the map
        l1.insert({1, 2});      // key , pair value must be in flower braces to be inserted
        auto it = l1.find(1);   // finding the address where key is 1
        l1.insert(it,{8,45});   // inserting 8,45 key-value pair at that position
        displayMap(l1);




        return 0;
}