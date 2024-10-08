#include <iostream>
using namespace std;
int main()
{
    int array[5] = {1, 2, 3, 4, 5};
    int num, index;
    cout << "Enter the index do you want replace number " << endl;
    cin >> index;
    cout << "Enter the number " << endl;
    cin >> num;
    bool replace = false;
    for (int i = 0; i < 5; i++)
    {
        if (index == i)
        {
            array[i - 1] = num;
            cout << "Number succesfully replaced in given index " << endl;
            replace = true;
            break;
        }
    }
    if (replace == false)
    {
        cout << "Element not updated " << endl;
    }
    cout << "The updated array is " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << array[i] << endl;
    }
    return 0;
}