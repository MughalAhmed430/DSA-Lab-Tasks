#include <iostream>
#include <string>
using namespace std;
struct Contact
{
    string name;
    string phoneNumber;
};

int linearSearch(Contact cont[], int n, string targetName)
{
    for (int i = 0; i < n; i++)
    {
        if (cont[i].name == targetName)
        {
            return i;
        }
    }
    return -1;
}


void sortContacts(Contact cont[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (cont[j].name > cont[j + 1].name)
            {
                Contact temp = cont[j];
                cont[j] = cont[j + 1];
                cont[j + 1] = temp;
            }
        }
    }
}

int binarySearch(Contact cont[], int low, int high, string targetName)
{
    if (low > high)
    {
        return -1; 
    }
    int mid = (low + high) / 2;
    if (cont[mid].name == targetName)
    {
        return mid;
    }
    else if (cont[mid].name > targetName)
    {
        return binarySearch(cont, low, mid - 1, targetName);
    }
    else
    {
        return binarySearch(cont, mid + 1, high, targetName);
    }
}

int main()
{
    int num;
    string targetName;

    cout << "Enter the number of contacts you want to Add: ";
    cin >> num;

    Contact cont[num];

    for (int i = 0; i < num; i++)
    {
        cout << "Enter the name for contact " << i + 1 << ": ";
        cin >> cont[i].name;
        cout << "Enter the phone number for contact " << i + 1 << ": ";
        cin >> cont[i].phoneNumber;
    }

    cout << "Enter the name of the contact you want to search for: ";
    cin >> targetName;

    int linearResult = linearSearch(cont, num, targetName);
    if (linearResult != -1)
    {
        cout << "Contact Found using Linear Search at index " << linearResult << " with phone number: " << cont[linearResult].phoneNumber << endl;
    }
    else
    {
        cout << "No contact found using Linear Search." << endl;
    }

    sortContacts(cont, num);
   
    int binaryResult = binarySearch(cont, 0, num - 1, targetName);
    if (binaryResult != -1)
    {
        cout << "Contact Found using Binary Search at index " << binaryResult << " with phone number: " << cont[binaryResult].phoneNumber << endl;
    }
    else
    {
        cout << "No Contact found using Binary Search." << endl;
    }

    return 0;
}
