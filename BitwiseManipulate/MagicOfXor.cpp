#include<iostream>
using namespace std;
int main()
{

// int a = 10 , b = 10 , c = 9;
// cout<<(a^b^c)<<endl;
// will return the odd times repeated number

int a[] = {1,1,1,1,2,8,2};
int n = sizeof(a)/sizeof(int);
int Xor = a[0];
for (int i = 1; i < n; i++)
{
    Xor ^= a[i];
    cout<<Xor<<endl;

}


return 0;
}