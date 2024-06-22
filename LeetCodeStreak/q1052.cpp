#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int k)
    {
        int n = customers.size();
        int original_sum = 0;
        for (int i = 0; i < n; i++)
        {
            if(grumpy[i] == 0){
                original_sum += customers[i];
            }
        }

        int maxi = -1;
        for (int i = 0; i <= n-k; i++)
        {
            int sum = 0;
            for (int j = 0; j < k; j++)
            {
                if(grumpy[i + j] == 1) sum += customers[i+j];
            }
            maxi = max(maxi, sum);
        }
        
        return original_sum + maxi;
    }
};


class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int k)
    {
        int n = customers.size();
        int original_sum = 0;
        for (int i = 0; i < n; i++)
        {
            if(grumpy[i] == 0){
                original_sum += customers[i];
            }
        }
        int additional_sum = 0;
        for (int i = 0; i < k; i++)
        {
             if(grumpy[i]) additional_sum += customers[i];
        }
        
        original_sum += additional_sum;
        int ans = original_sum;
        for (int i = 1; i <= n-k; i++)
        {
            if(grumpy[i-1]) original_sum -= customers[i-1];
            if(grumpy[i + k - 1]) original_sum += customers[i + k - 1];
            ans = max(ans, original_sum);
        }
        
        return ans;
    }
};


int main()
{

    return 0;
}