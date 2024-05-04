#include<bits/stdc++.h>
using namespace std;

int minOperations(string s) {
    int minCount = 1e9, count = 0;
    bool it = false;
    for(int j = 0; j < 2 ; j++){
        count = 0;
        it = j;
        for(auto ch : s){
            // cout<<ch<<" "<<it<<" "<<count<<endl;
            if(it == 0 && ch == '1' || it == 1 && ch == '0')
                count++;
            it = !it;
        }
        // cout<<count<<endl;
        minCount = min(minCount, count);
    }
    
    return minCount;
}


int main()
{
    // string s = "0100";
    // string s = "1111";
    string s = "10010100";
    cout<<minOperations(s);

return 0;
}