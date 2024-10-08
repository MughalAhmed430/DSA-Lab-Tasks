#include <iostream>
using namespace std;

int main()
{

    int searchValue;
    cout << "Enter Search Value: ";
    cin >> searchValue;
    int numbers[4][4] = {{12, 34, 23, 34},{78, 56, 89, 12},{34, 12, 45, 67},{90, 23, 56, 78}};

    bool found = false;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (numbers[i][j] == searchValue)
            {
                found = true;
                cout <<"Search Found at : " << i << "," << j <<endl;
                break;
            }
        }
        if (found)
            break;
    }
    if (!found)
    {
        cout << "\n Search Not Found" << endl;
    }

    return 0;
}