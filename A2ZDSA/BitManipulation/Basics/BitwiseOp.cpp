#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num = 5;  //101
    int i = 2;
    // get bit at a index of i
    cout<<(((1 << i) & num) != 0)<<endl;
    // set bit at a index of i
    cout<<((1 <<i ) | num)<<endl;
    // clear bit a index of i
    cout<<(~(1<<i) & num )<<endl;
return 0;
}