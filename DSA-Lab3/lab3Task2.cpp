#include <iostream>
using namespace std;
int binarySearch(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 5, 12, 23, 38, 45, 62};

    int size = sizeof(arr) / sizeof(arr[0]);
    int target;
    cout << "Enter the value you want to search:\t";
    cin >> target;
    int result = binarySearch(arr, size, target);
    if (result != -1)
    {
        cout << "Element " << target << " found in the array " << result << endl;
    }
    else
    {
        cout << "Element " << target << " not found in the array" << endl;
    }

    return 0;
}