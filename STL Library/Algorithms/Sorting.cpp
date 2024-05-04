#include <iostream>
#include <algorithm>

using namespace std;

void show(int a[], int array_size)
{
    for (int i = 0; i < array_size; ++i)
        cout << a[i] << " ";
}

int main()
{
    int arr[] = {1, 2, 3, 43, 5, -1, -90};
    int n = sizeof(arr) / sizeof(int);

    sort(begin(arr), end(arr)); // This will be executing through stl library
    show(arr, n);

    return 0;
}
