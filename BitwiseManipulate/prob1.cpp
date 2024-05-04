// Solve for 2 numbers that are only repeating once in
// the array

#include <iostream>
#include <algorithm>
using namespace std;

void displayArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {2, 2, 3,10, 4, 4, 5, 1, 1,1,1};
    int n = sizeof(arr) / sizeof(int);

    // i want a  sorted array
    sort(arr, arr + n);
    displayArr(arr, n);
    int count = 0;
    for (int i = 1; i < n - 1; i++)
    {

        if (i == 1)
        {
            if ((arr[i - 1] != arr[i]))
            {
                cout << arr[i-1] << " ";
                count++;
            }
        }
        if (i == n - 2)
        {
            if ((arr[i] != arr[i + 1]))
            {
                cout << arr[i+1] << " ";
                count++;
            }
        }

        
        if ((arr[i - 1] != arr[i]) && (arr[i] != arr[i + 1]))
        {
            cout << arr[i] << " ";
            count++;
        }
    }
    cout << "\n"<< count << endl;

    return 0;
}