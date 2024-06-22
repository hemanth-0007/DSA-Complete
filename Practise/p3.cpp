#include<bits/stdc++.h>
using namespace std;




bool isPrime(int n){
    if(n == 1) return false;
    if(n == 2) return true;
    for(int i = 2 ; i < n; i++ ){
        if(n%i == 0) return false;
    }
    return true;
}



int main() {
     int n;
     int sum = 0;
    //  cin>>n;
    n = 2;
     int prevNum = 0;
     int curNum = 1;
     while(curNum <= n){
         int newSeq = curNum + prevNum;
         prevNum = curNum;
         curNum = newSeq;
         cout<<curNum<<endl;
         if(curNum > n ) break;
         if(isPrime(curNum)) sum += curNum;
     }
      
     cout<<sum<<endl;
  return 0;
}