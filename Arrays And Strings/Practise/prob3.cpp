 #include<bits/stdc++.h>
 using namespace std;
 
    int isPrime(int n){
        if(n == 2 )
        return 1;
        
        for(int i = 2;i<n ;i++){
            if(n%i == 0){
                return 0;
            }
        }
        return 1;
    }
    vector<int> leastPrimeFactor(int n) {
        vector<int> res;
        for(int i=0;i<=n;i++){
            if(i==1 || i ==0)
                res.push_back(i);
            for(int j=2;j<=i;j++){
                
                if(isPrime(j)){
                    if(i%j == 0){
                        res.push_back(j);
                        break;
                    } 
                }
            }
        }
        return res;
    }
 

 int main()
 {
    int n = 12;
    vector<int> vec = leastPrimeFactor(n);
    for (int i = 0; i <= n; i++)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    
    for(auto num : vec){
        cout<<num<<" ";
    }
 
 return 0;
 }