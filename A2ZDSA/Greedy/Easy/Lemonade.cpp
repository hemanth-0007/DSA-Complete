#include<bits/stdc++.h>
using namespace std;
bool lemonadeChange(vector<int>& arr) {
    int n = arr.size();
    int five = 0, ten = 0;
    for (int i = 0; i < n; i++)
    {
        int bill = arr[i];
        if(bill == 5) five++;
        else if(bill == 10){
            ten++;
            five--;
        }
        else if(bill == 20){
            // 5 5 5 or 5 10
            if(ten >= 1 && five >= 1){
                ten--; five--;
            }
            else{
                five -= 3;
            }
        }
        if(five < 0 || ten < 0) return false;
    }
    return true;
}
int main()
{

return 0;
}