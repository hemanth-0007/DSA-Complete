 //Finding the element in the row r and column c is (r-1)C(c-1)

#include<bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
long long res = 1;

// calculating nCr:
// tc ->O(r)
//sc ->O(1)
for (int i = 0; i < r; i++) {
    res = res * (n - i);
    res = res / (i + 1);
}
return res;
}

int main()
{
int n = 5;
cout<<nCr(5,0)<<endl;
cout<<nCr(5,1)<<endl;
cout<<nCr(5,2)<<endl;
cout<<nCr(5,3)<<endl;
cout<<nCr(5,4)<<endl;
return 0;
}