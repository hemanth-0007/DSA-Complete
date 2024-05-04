#include<bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:
    set<int> st;
    RandomizedSet() {
        st = {};
    }
    
    bool insert(int val) {
        if(st.find(val) == st.end()){
            st.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(st.find(val) != st.end()){
            st.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<size_t> dis(0, st.size() - 1);
        size_t randomIndex = dis(gen);
        auto it = st.begin();
        advance(it, randomIndex);

       
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{
 RandomizedSet* obj = new RandomizedSet();
 bool param_1 = obj->insert(10);
 obj->insert(1);
 obj->insert(13);
 obj->insert(9);
 obj->insert(90);
 bool param_2 = obj->remove(90);
 int param_3 = obj->getRandom();
 cout<<param_1<<" "<<param_2<<" "<<param_3;

return 0;
}