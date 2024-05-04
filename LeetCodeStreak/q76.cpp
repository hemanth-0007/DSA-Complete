#include<bits/stdc++.h>
using namespace std;


 
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        vector<int> map(128, 0);
        int count = t.length();
        int start = 0, end = 0, minLen = INT_MAX, startIndex = 0;
         
        for (char c : t) {
            map[c]++;
        }

        while (end < s.length()) {
            cout<<"Inside 1st loop"<<endl;
            cout<<start<<" "<<end<<endl;
            if (map[s[end++]]-- > 0) {
                count--;
            }

            while (count == 0) {
                cout<<"\t"<<"Inside 2nd loop"<<endl;
                cout<<"\t\t"<<start<<" "<<end<<endl;
                if (end - start < minLen) {
                    startIndex = start;
                    minLen = end - start;
                }

                if (map[s[start++]]++ == 0) {
                    count++;
                }
                cout<<"\t\tmin Length "<<minLen<<endl;
                cout<<"\t\tstart Ind "<<startIndex<<endl;
                cout<<"\t\tcount  "<<count<<endl;
                
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
 




// string minWindow(string s, string t) {
//     int n = s.size(), m = t.size();
//     if(m > n) return "";
//     vector<int> map(126, 0);
//     for(auto ch : t) map[ch]++;
//     int start = 0 , end = 0, count = t.size();
//     int minLen = INT_MAX, startInd = 0;
//     while(end < s.size()){
//         cout<<"Inside 1st loop"<<endl;
//         if(map[s[end++]]-- > 0) count--;
//         cout<<start<<" "<<end<<endl;
//         while(count == 0){
//             cout<<"Inside 2nd loop"<<endl;
//             if(minLen > end - start){
//                 startInd = start;
//                 minLen = end - start;
//             }
//             if(map[s[start++]]++ > 0) count++;
//             cout<<"min Length "<<minLen<<endl;
//             cout<<"startInd "<<startInd<<endl;
//         }
//         cout<<"min Length"<<minLen<<endl;
//     }
//     return minLen == INT_MAX ? "" : s.substr(startInd, minLen);

// }


int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout<<minWindow(s, t);

return 0;
}