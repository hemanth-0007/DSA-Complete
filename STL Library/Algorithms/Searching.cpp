#include<iostream>
#include<algorithm>
using namespace std;


int sum(int a, int b){
    return a+b;
}
int main()
{
    int a[] = {
     1,89,34,23,-90
    };
    sort(a+1, a+5);// Intro sort 
    // bool val = binary_search(a, a+5,23);
    // cout<<val;
    for (int i = 0; i < 5; i++)
    {
        cout<<a[i]<<" ";
    }
     
    
return 0;
}