#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int array[10] = {34, 7, 23, 32, 5, 62};
    int target, size;
    cout << "Enter the Element you want to Target:" << "\t";
    cin >> target;
    size = sizeof(array) / sizeof(array[0]);
    int result = linearSearch(array, size, target);
    if (result != -1)
    {
        cout << "\nThe Element " << target <<  " Found in the Array at Index :" << result << endl;
    }
    else
    {
        cout << "The Element " << target << "  not Found in the Array" << endl;
    }
    return 0;
}