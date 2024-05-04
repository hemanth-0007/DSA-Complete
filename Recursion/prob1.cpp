#include<iostream>
using namespace std;
void func( int n ){
    if(n == 0)
    return ;
    // Base condition 
    n--;
    cout<<n<<endl; 
    func(n); 
   
}
int main()
{
int n = 5, i = 0;
func(n);
return 0;
}