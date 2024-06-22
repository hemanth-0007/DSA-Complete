#include <bits/stdc++.h>
using namespace std;
class LFUCache
{
public:
    map<int, list<pair<int,int>> :: iterator> keyNode;
    map<int , list<pair<int,int>>> freqMap;
    int freq;
    int size;
    int cap;
    LFUCache(int capacity)
    {
        freq = 0;
        size = 0;
        cap = capacity;
    }

    
    int get(int key)
    {
        
    }

    void put(int key, int value)
    {
       if(keyNode.find(key) != keyNode.end()){

       }
       else{
            if(size == cap){

            }
            else{
                freq = 1;
            }
       }
    }
};
int main()
{

    return 0;
}