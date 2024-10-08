#include <iostream>
using namespace std;
int recursion(int arr[], int high, int low, int key)
{
    int mid = (high + low) / 2;
    if (low > high)
    {
        return -1;
    }
    if (arr[mid] == key)
    {
        return mid;
    }
    else if (arr[mid] > key)
    {
        return recursion(arr, mid - 1, low, key);
    }
    if (arr[mid] < key)
    {
        return recursion(arr, high, mid + 1, key);
    }
}
int main()
{
    int arr[6]={15,18,2,3,6,12};
   
    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 6; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    int key;
    cout << "Enter the value to be searched: ";
    cin >> key;
    int result = recursion(arr, 6 - 1, 0, key);
    if (result != -1)
    {
        cout << "The Number " << key << " is Found at index " << result;
    }
    else
    {
        cout << "The Number is not Found in array";
        
    }
}