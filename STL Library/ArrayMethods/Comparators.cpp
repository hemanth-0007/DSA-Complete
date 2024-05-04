// A C++ program to demonstrate
// STL sort() using
// our own comparator
#include <bits/stdc++.h>
using namespace std;

// An interval has a start
// time and end time
struct Interval {
	int value, wt;
};

// Compares two intervals
// according to starting times.
bool compareInterval(Interval i1, Interval i2)
{
	return ((i1.value/i1.wt) > (i2.value/i2.wt)) ;
}

int main()
{
	Interval arr[]
		= { {60,10},{100,20}, {120,30} };
	int n = sizeof(arr) / sizeof(arr[0]);

	 
	sort(arr, arr + n, compareInterval);

	cout << "Intervals sorted by start time : \n";
	for (int i = 0; i < n; i++)
		cout << "[" << arr[i].value << "," << arr[i].wt
			<< "] ";

	return 0;
}
