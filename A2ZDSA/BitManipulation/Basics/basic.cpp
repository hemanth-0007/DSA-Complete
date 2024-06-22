#include <bits/stdc++.h>
using namespace std;

// set the rightmost unset bit
int setBit(int N)
{
    for (int i = 0; i < 32; i++)
    {
        if((N&(1<<i)) == 0){
            N = N | (1<<i);
            break;
        }
    }
    return N;
}

int main()
{
    int n = 2; // 010
    cout << __builtin_popcount(n) << endl;
    cout << __builtin_clz(n) << endl; // number of leading zeros

    //  swapping a b
    int a = 10, b = 20;
    a ^= b;
    b ^= a;
    a ^= b;
    cout << "a is " << a << endl;
    cout << "b is " << b << endl;


    int x = 6; // 110
    int y = setBit(x);
    cout<<"x is :"<<x<<endl;
    cout<<"y is after setting rightmost unset :"<<y<<endl;


    int p = -2147483648;
    p--;
    cout<<"val of p is: ";
    cout<<p<<endl;

    return 0;
}