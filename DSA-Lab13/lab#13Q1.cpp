#include <iostream>
#include <string>

using namespace std;

struct Record {
    int sapID;
    string name;
};

void displayRecords(Record records[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << records[i].sapID << "\t" << records[i].name << endl;
    }
    cout << endl;
}
void bubbleSort(Record records[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (records[j].sapID > records[j + 1].sapID) {
                Record temp = records[j];
                records[j] = records[j + 1];
                records[j + 1] = temp;
            }
        }
    }
}
void insertionSort(Record records[], int size) {
    for (int i = 1; i < size; ++i) {
        Record key = records[i];
        int j = i - 1;
        
        while (j >= 0 && records[j].sapID > key.sapID) {
            records[j + 1] = records[j];
            j = j - 1;
        }
        records[j + 1] = key;
    }
}
int main() {
    const int SIZE = 33; 
    Record records[SIZE] = {
        {44391, "Zarar . Khan"}, {44647, "ABDUL MOIZ . MANSAB"},
        {47777, "Shabir . Ahmad"}, {53759, "ahmed . Irtaza"},
        {55181, "Asad . Ullah"}, {55223, "Ahmed . Aziz"},
        {55225, "Uzair . Baig"}, {55330, "Haider . Nawaz Thabal"},
        {55349, "Muhammad Hamza Shakeel"}, {55356, "Usman Afzal Minhas"},
        {55405, "Shujaat . Hussain"}, {55434, "Mahboob . Rasheed"},
        {55465, "Hafiz Muhammad . Hamza Hashmi"}, {55469, "Uzair Ahmed Qureshi"},
        {55566, "rafay . jadoon"}, {55579, "Muhammad . Shameel"},
        {55584, "Anees . Ahmed"}, {55590, "Ghazanfar . Pasha"},
        {55632, "Muhammad . Waqas"}, {55633, "Muhammad . Amman Ullah"},
        {55652, "Shahzaib . Adil"}, {55691, "Said . Rasool"},
        {55700, "MUHAMMAD . WALEED"}, {55766, "Sufyan Ahmed Mughal"},
        {55780, "Haroon Abbas Abbas"}, {55843, "Abrar . Ali"},
        {55853, "Farhan . UL Haq"}, {56067, "Mehmood . khan"},
        {56154, "Umer . Farooq"}, {56177, "Muhammad Roshaan Idrees"},
        {56274, "Ahmed . Tariq"}, {56673, "Saad . Ali"} , {56765, "Muhammad HAMMAD .Liaquat"}
    };

    cout << "Original Records:\n";
    displayRecords(records, SIZE);

    Record bubbleSortedRecords[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        bubbleSortedRecords[i] = records[i]; 
    }
    bubbleSort(bubbleSortedRecords, SIZE);
    cout << "Records after Bubble Sort:\n";
    displayRecords(bubbleSortedRecords, SIZE);

    Record insertionSortedRecords[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        insertionSortedRecords[i] = records[i]; 
    }
    insertionSort(insertionSortedRecords, SIZE);
    cout << "Records after Insertion Sort:\n";
    displayRecords(insertionSortedRecords, SIZE);

return 0;
}