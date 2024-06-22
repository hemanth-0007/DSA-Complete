#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
private:
    list<pair<int,int>> dq;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    int size = 0;
public:
    LRUCache(int capacity)
    {
        size = capacity;
    }

    int get(int key)
    {
        if(mp.find(key) != mp.end()){
            auto itr = mp[key];
            int val = itr->second;
            dq.erase(itr);
            dq.push_back({key, val});
            mp[key] = --dq.end();
            return val;
        }
        return -1;
    }
    void print_de(){
        for(auto it : dq) cout<<it.first<<"/"<<it.second<<" ";
    }

    void put(int key, int value)
    {
        if(mp.find(key) != mp.end()){
            auto itr = mp[key];
            dq.erase(itr);
            dq.push_back({key, value});
            mp[key] = --dq.end();
        }
        else{
            if (mp.size() == size)
            {
                // Remove the least recently used element
                auto lru = dq.front();
                mp.erase(lru.first);
                dq.pop_front();
            }
            dq.push_back({key, value});
            mp[key] = --dq.end(); 
        }
        print_de();
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main()
{

    int capacity = 2, key = 10, value = 5;
    LRUCache *obj = new LRUCache(capacity);
    int param_1 = obj->get(key);
    obj->put(key, value);

    return 0;
}