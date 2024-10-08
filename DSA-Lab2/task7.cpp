#include <iostream>
using namespace std;
int main()
{
    const int length = 4;
    int matrix[length][length];
    int key;
    bool found = false;


    cout << "Enter the elements of a 4x4 matrix:" << endl;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "Enter the value to search for: ";
    cin >> key;

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (matrix[i][j] == key)
            {
                cout << "Value " << key << " found at row " << i << " and column " << j << "." << endl;
                found = true;
                break;
            }
        }
        if (found)
            break;
    }

    if (!found)
    {
        cout << "Value " << key << " not found in the matrix." << endl;
    }

    return 0;
}