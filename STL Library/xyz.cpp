#include<bits/stdc++.h>
using namespace std;

 

 


int getVar(string s){
    map<char, int> mpp;
     int maxi = -1e9 , mini = 1e9;
    for(auto ch : s)
        mpp[ch]++;
    if(mpp.size() == 1) return 0;
     for(auto itr :mpp){
        maxi = max(maxi, itr.second);
        mini = min(mini, itr.second);
     }
     return (maxi-mini);
}


int maxSubStrVar(string s){
    int n = s.size(), maxi = -1e9;
    string str = "";
    for (int i = 0; i < n; i++)
    {   
        for (int j = i; j < n; j++)
        {
            str += s[j];
            maxi = max(maxi ,getVar(str));
        }
        str.clear();
        
    }
    return maxi;
}


int main()
{
    // time complexity time exceeded error
    string s = "elbodkxuslqfgthxpaeqyffgrpdrdzsoywqmorepolpwnlaeaunbhchttdfkuaxkbkixnpynfrnfaszlwneufweqzkunadtzabhplqfieptkobwbjwwkqkleidohvzyethdozmtfgponjqelcltptmmjehsdrpinwokxdouhsrsppdksmmaudslaitrtkzpfpkkwbuhibfnxjjrtliwdeosuhyjtjwirerdybqgbgwrdwjcyonsnhoqpwcbmrtxapmvljoeqqtznqdspvayrdoskunquplejzfhfbmpanhxxbxarwexpbjxbocxhdqbhzfktapltkxypwfssawifpthgfsedzxvnqhdifscmdalfntvrebrjbsvauvkjtzvuqlvyzknrnxirjetjudtukucpvnmtwkharebrg";
    cout<<maxSubStrVar(s);

return 0;
}