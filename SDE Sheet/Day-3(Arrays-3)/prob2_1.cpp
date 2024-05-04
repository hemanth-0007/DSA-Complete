//gives the pow(x, n) x^n on various different constraints

#include<bits/stdc++.h>
using namespace std;

double pow(double x, int n){

    double ans = 1.0;
    int flag = 0;
    if(n < 0){
        flag = 1;
        n = (-1)*n;
    }
    while (n)
    {
        if( (n%2)== 0){
            x =  x*x;
            n = n/2;
        }
        else{
            ans = ans*x;
            n = n - 1;
        }
    }

    if(flag == 1) ans = double(1)/ans;
    return ans;
}








int main()
{
    double x = 2.0;
    int n = -1;
    cout<<pow(x,n);
return 0;
}