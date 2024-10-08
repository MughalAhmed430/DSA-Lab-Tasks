#include <iostream>
using namespace std;

bool isPalindrome(int arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        if (arr[i] != arr[size - 1 - i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    const int size = 6;
    int array[size];

    cout << "Enter 6 integers: " << endl;
    for (int i = 0; i < size; ++i)
    {
        cin >> array[i];
    }
    if (isPalindrome(array, size))
    {
        cout << "The array represents a palindrome." << endl;
    }
    else
    {
        cout << "The array does not represent a palindrome." << endl;
    }

    return 0;
}