#include<bits/stdc++.h>
using namespace std;

int main() {
     vector<int> numbers = {3, 2, 5,78,7,10};
    auto itr = numbers.begin() + 4;
    // Find the maximum element using std::max_element
    auto maxElement =  min_element(numbers.begin(), itr);
    
    // if (maxElement != numbers.end())  
        cout << "The maximum element is: " << *maxElement << std::endl;
  
    
    return 0;
}

 