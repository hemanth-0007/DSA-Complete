// Ram has an array A
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

// Function to generate all divisors of a given number
set<int> getDivisors(int num) {
    set<int> divisors;
    for (int i = 1; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            divisors.insert(i);
            if (i != num / i) {
                divisors.insert(num / i);
            }
        }
    }
    return divisors;
}

// Function to check if the array can be transformed into a strictly increasing array
bool canTransformToStrictlyIncreasing(vector<int>& A) {
    int n = A.size();
    for (int i = 0; i < n - 1; ++i) {
        if (A[i] >= A[i + 1]) {
            // Current element A[i] is not strictly less than the next element A[i + 1]
            set<int> divisors = getDivisors(A[i]);
            bool canReplace = false;
            for (int div : divisors) {
                if (div < A[i + 1] && (i == 0 || div > A[i - 1])) {
                    // Check if this divisor can be placed at position i
                    canReplace = true;
                    A[i] = div;
                    break;
                }
            }
            if (!canReplace) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    // vector<int> A = {4, 10, 6, 8, 12}; // Example input
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    if (canTransformToStrictlyIncreasing(arr)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
