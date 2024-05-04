#include<iostream>
using namespace std;

/*
   In Recursive Functions:
    It is very important to add a base case  
    otherwise recursive function will never 
    stop executing.

    
   for example: 
   factorial(2);

   first it checks the base consition <= 0 
   then if not 
   it returns 2*factorail(1);
   then       2*1*factorial(0);    
   results in == 2*1*1 = 2


*/


int factorial(int n ){
    if(n<= 0 ){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}


int main()
{
    cout<<factorial(5);

return 0;
}