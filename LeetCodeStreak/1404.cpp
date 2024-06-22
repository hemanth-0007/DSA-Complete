#include <bits/stdc++.h>
using namespace std;

bool isOne(const string &s)
{
    int n = s.size();
    for (int i = 0; i < n - 1; i++)
        if (s[i] == '1')
            return false;
    if (s[n - 1] == '1')
        return true;
    return false;
}

int numSteps(string s)
{
    int op = 0;

    while (!isOne(s))
    {
        int n = s.size();
        if (s[n - 1] == '0')
        {
            s = '0' + s;
            s.pop_back();
            // cout<<"evn "<<s<<endl;
        }
        else
        {
            int j = n - 2;
            int carry = 1;
            s[n - 1] = '0';
            while (j >= 0 && carry == 1)
            {
                if (carry == 1 && s[j] == '1')
                {
                    s[j] = '0';
                }
                else if (carry == 1 && s[j] == '0')
                {
                    s[j] = '1';
                    carry = 0;
                }
                j--;
            }
            if (carry == 1)
                s = '1' + s;
            // cout<<"odd "<<s<<endl;
        }
        op++;
    }

    return op;
}



int numStepsOp(string s)
{
    int op = 0;
    int n = s.size();
    int j = n-1;
    int carry = 0;
    while ( j > 0 )
    { 
        // carry 0 and s[j] 0 so even number
        if(s[j] - '0' + carry == 0){
            carry = 0;
            op++;
        }
        else if(s[j] - '0' + carry == 2){
            // carry 1 and s[i]  1 so even
            carry = 1;
            op++;
        }
        else{
            // s[j] 1 and carry 0 
            // s[j] 0 and carry 1
            carry = 1;
            op += 2;
        }
        j--;
    }
    if(carry == 1) op++;

    return op;
}

int main()
{
    string s = "1101";
    cout<<numSteps(s)<<endl;
    cout<<numStepsOp(s)<<endl;

    return 0;
}