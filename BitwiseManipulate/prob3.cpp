// C++ program for above approach
#include <bits/stdc++.h>
using namespace std;

/* This function sets the values of
*x and *y to non-repeating elements
in an array arr[] of size n*/
vector<int> get2NonRepeatingNos(int nums[], int n)
{

	sort(nums, nums + n);

	vector<int> ans;
	for (int i = 0; i < n - 1; i = i + 2) {
		if (nums[i] != nums[i + 1]) {
			ans.push_back(nums[i]);
			i = i - 1;
		}
	}

	if (ans.size() == 1)
		ans.push_back(nums[n - 1]);

	return ans;
}

/* Driver code */
int main()
{
	int arr[] = { 1,1,1,2,2,2,3,4,5 };
	int n = sizeof(arr) / sizeof(*arr);
	vector<int> ans = get2NonRepeatingNos(arr, n);
	cout << "The non-repeating elements are " << ans[0]
		<< " and " << ans[1];
}

// This code is contributed by rathbhupendra
