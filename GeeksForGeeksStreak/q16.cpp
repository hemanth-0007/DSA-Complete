#include<bits/stdc++.h>
using namespace std;


void trim(string &s){
    string t;
    int n = s.size(),i = 0,j = n-1;
    while(s[i] == ' '){i++;}
    while(s[j] == ' '){s.pop_back(); j--;}
    // cout<<i<<" "<<j<<endl;
    // for (int k = i; k <= j; k++) t.push_back(s[k]);
    s.erase(0, i);
    return;
}
 
int atoi(string s){
    trim(s);
    int n = s.size();
    int extractedNum = 0;
    bool isNeg = false;
    for(int i = 0; i < n; i++){
        if(i == 0 && s[i] == '-'){
             isNeg = true;
             continue;
        }
        if(isdigit(s[i])){
            int x = s[i] - '0';
            extractedNum  = extractedNum*10 + (s[i] - '0');
        }
        else return -1;
    }
        return isNeg ? (-1)*extractedNum  : extractedNum;

}


int main()
{
    // cout<<char(45)<<endl;
    string s  = "  -34";
    cout<<s<<endl;
    // trim(s);
    // cout<<s<<endl;
    cout<<atoi(s);
return 0;
}