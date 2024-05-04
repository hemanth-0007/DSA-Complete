#include<iostream>
using namespace std;

// printing the sum of first n natural numbers using recursion
// i -> n = 5 s = 0
int sum(int i, int s){

    if(i == 0){
        return s;
    }
   
    sum(i - 1 , s + i); 
   
} 


int sum(int n )
{
    if (n == 0)
    {
        return 0;
    }
    return n + sum(n-1);
    
}
int main()
{
int n = 5 , s =0;
 sum(n, s);
 cout<<endl<<sum(n,s);
return 0;
}