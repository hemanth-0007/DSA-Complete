#include<bits/stdc++.h>
using namespace std;



int nene_func(vector<int>& sequence, int n){
    int k = sequence.size();
    int prev_n = n, cur_n = n;
    do
    {
        prev_n = n;
        for(auto num : sequence){
            if(num <= n){
                n = n - 1;
            }
            else break;
        }
        cur_n = n;
    } while (prev_n != cur_n);
    return cur_n;
}





int main()
{
    // vector<int> sequence = {3, 5};
    // int n = 5;
    // cout<<nene_func(sequence, n);
    int testcases;
    cin>>testcases;
    while (testcases--)
    {
        int k , q;
        cin>>k>>q;
        vector<int> sequence(k);
        for (int i = 0; i < k; i++)
            cin>>sequence[i];
        for (int j = 0; j < q; j++){
            int n;
            cin>>n;
            cout<<nene_func(sequence, n)<<" ";
        }
        cout<<endl;
    }
    

return 0;
}