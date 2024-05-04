#include <iostream>
#include <random>
#include <chrono>
using namespace std;

int main() {
    // Get the current time as a seed for the random number generator
    unsigned seed =  chrono::system_clock::now().time_since_epoch().count();

    // Create a random number generator object using the seed
     mt19937 rng(seed);

    // Define the range of the random number
    int min = 0;
    int max = 1;

    // Create a distribution object that maps the random number to the desired range
    uniform_int_distribution<int> uni(min, max);

    // Generate a random number
    int random_number = uni(rng);

    // Output the random number
    cout << "Random number: " << random_number << endl;

    return 0;
}
