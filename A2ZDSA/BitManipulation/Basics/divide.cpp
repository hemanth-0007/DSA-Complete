#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor)
{
    if(dividend == divisor)  return 1;
    bool isPositive = (divisor < 0 == dividend < 0);
    unsigned int a = abs(dividend);
    unsigned int b = abs(divisor);
    unsigned int ans = 0;
    while (a >= b)
    {
        short q = 0;
        while(a > (b<<(q+1))) q++;// checking to include the q+1 or not then only including the q
        ans += (1<<q);
        a = a - (b<<q);
    }
    if(ans == (1<<31)) return INT_MAX;
    return isPositive ? ans : (-1)*ans; 
}

int main()
{
    cout<<divide(50, 7);

    return 0;
}