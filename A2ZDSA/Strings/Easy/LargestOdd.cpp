#include<bits/stdc++.h>
using namespace std;

string largestOddNumber(string num) {
    int n = num.size();
    int i = n-1;
    while(i >= 0){
        if(((num[i] - '0') & 1) != 0) break;
        i--;
    }       
    if(i >= 0) return num.substr(0 , i+1);
    return "";
}


int main()
{
    string num = "4205";
    cout<<largestOddNumber(num)<<endl;

return 0;
}