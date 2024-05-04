#include<bits/stdc++.h>
using namespace std;

int main() {
     vector<int> numbers = {3, 7, 2, 9, 5};
    int target = 34;
    
    
    auto found = find(numbers.begin(), numbers.end(), target);
    
    if (found != numbers.end()) {
        cout << "Element is: " <<*found<< endl;
    } else {
        cout << "Element not found" << endl;
    }
    
    return 0;
}
 