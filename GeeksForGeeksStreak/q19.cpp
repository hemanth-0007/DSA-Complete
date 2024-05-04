#include<bits/stdc++.h>
using namespace std;

// F(5) = 1 + 2*3 + 4*5*6 + 7*8*9*10 + 11*12*13*14*15 = 365527.


long long sequence(int n){
    long long ans = 1;
    int j = 1;
    for (int i = 1; i <= n; i++)
    {
        long long temp = 1;
        int k = 1;
        // while(k <= i){
        //     cout<<j<<" ";
        //     temp *= j;
        //     k++;
        //     j++;
        // }
        for (int k = 1; k <= i; k++)
        {
            cout<<j<<" ";
            temp *= (j++);
        }
        ans += temp;
        cout<<endl;
    }
    return ans;
}


long long sequenceOp(int n){
    long long MOD = 1e9 + 7;
    long long ans = 0;
    int j = 1, i = 1;
    for (i = 1; i <= n; i++)
    {
        long long temp = 1;
        for (int k = 1; k <= i; k++) {
            temp *= (j++);
            temp = temp%MOD;
        }
        // cout<<temp<<endl;
        ans += temp;
        ans = ans%MOD;
    }
    return ans;
}


int main()
{
    cout<<sequence(7)<<endl;
    cout<<sequenceOp(7)<<endl;

return 0;
}