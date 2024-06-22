#include <bits/stdc++.h>
using namespace std;

// this Algorithm dont maintain the order****
void zerosToEndMod(vector<int> &arr)
{
    int n = arr.size();
    int i = 0, j = n - 1;
    while (i <= j)
    {
        if (arr[j] == 0)
            j--;
        else if (arr[i] == 0)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        else if (arr[j] != 0)
            i++;
    }
}

void zerosToEnd(vector<int> &arr)
{
    int n = arr.size();
    int i = 0, j = 1;
    while (i < j && j < n && i < n)
    {
        if (arr[i] == 0 && arr[j] != 0)
        {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
        else if (arr[i] == 0 && arr[j] == 0)
            j++;
        else
        {
            i++;
            j++;
        }
    }
}

void zerosToEndOp(vector<int> &arr)
{
    int n = arr.size();
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
        return;
    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main()
{
    vector<int> arr = {1, 0, 2, 3, 0, 4, 0, 1};
    // zerosToEndMod(arr);
    // zerosToEnd(arr);
    zerosToEndOp(arr);
    for (auto num : arr)
        cout << num << " ";

    return 0;
}