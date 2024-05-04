#include<bits/stdc++.h>
using namespace std;
// O(n) time and O(n) space
vector<int> dailyTemperatures(vector<int>& temp) {
    int n = temp.size();
    vector<int> result(n);
    // to store the index of the elements in the deque
    list<int> deque;
    for(int i = n-1; i >=0 ; i--){
        if(deque.size() == 0){ 
            result[i] = 0;
            deque.push_front(i);
            continue;
        }
        while( temp[i] >= temp[deque.front()] && deque.size() > 0 ){
            deque.pop_front(); 
        }
        if(deque.size() > 0) result[i] = deque.front() - i;
        else result[i] = 0;
        deque.push_front(i);
    }
    return result;
}



vector<int> dailyTemperaturesOptimal(vector<int>& temp) {
    int n = temp.size();
    vector<int> ans(n, 0);
    int hottestTemp = temp[n-1];
    for (int i = n-2; i >= 0 ; i--)
    {
        if(temp[i] >= hottestTemp){
            hottestTemp = temp[i];
            continue;
        }
        int days = 1;
        while( temp[i] >= temp[i + days]){
            days += ans[i + days];
        }
        ans[i] = days;
    }
    return ans;
}

int main()
{
    // vector<int> temp = {73,74,75,71,69,72,76};
    vector<int> temp = {89,62,70,58,47,47,46,76,100,70};
    vector<int> result = dailyTemperatures(temp);
    for(int i = 0; i < temp.size(); i++){
        cout << temp[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }

return 0;
}