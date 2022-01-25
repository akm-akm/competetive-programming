#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;
long long ar[500000];
double t1, t2, t3, sizeArray;
int sortIn = 0;

void menu()
{
    cout << "\t\tMENU " << endl;
    cout << "0. Quit" << endl;
    cout << "1. Create Array of length n" << endl;
    cout << "2. Display the Array" << endl;
    cout << "3. Sort the Array" << endl;
}

void quit()
{
    exit(0);
}
void clearTerminal()
{
    cout << "\033[2J\033[1;1H";
}
void displayArray()
{

    clearTerminal();
    if (sizeArray == 0)
    {
        cout << "Array is empty" << endl;
        cout << "\n\nPress any key to go back to menu" << endl;
        cin.ignore();
        cin.get();
        clearTerminal();
        return;
    }
    cout << "Array of length " << sizeArray << " is - " << endl;
    cout << endl;
    for (int i = 0; i < sizeArray; ++i)
    {
        cout << ar[i] << " ";
    }
    cout << "\n\nPress Enter to go back to menu" << endl;
    cin.ignore();
    cin.get();
    clearTerminal();
}

void randomData()
{

    cout << "Enter size of array > ";
    cin >> sizeArray;
    for (int i = 0; i < sizeArray; ++i)
    {
        ar[i] = rand() % 100;
    }
}

////////////////////////////////////////////////////////////////////////

void bubbleSort()
{
    clearTerminal();
    cout << "Bubble Sort is Running, please wait for it to finish!" << endl;

    long temp[500000];
    bool isSwapped;
    for (int i = 0; i < sizeArray; i++)
    {
        temp[i] = ar[i];
    }
    clock_t start = clock();
    for (int i = 0; i < sizeArray - 1; i++)
    {
        isSwapped = false;

        for (int j = 0; j < sizeArray - i - 1; j++)
        {
            if (temp[j] > temp[j + 1])
            {
                swap(temp[j], temp[j + 1]);
                isSwapped = true;
            }
        }
        if (isSwapped == false)
            break;
    }
    clock_t end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Bubble Sort took " << time_taken << " seconds to execute \n";
    cout << "Press Enter " << endl;
    cin.ignore();
    cin.get();
}

void selectionSort()
{
    clearTerminal();
    cout << "Selection Sort is Running, please wait for it to finish!" << endl;

    long temp[500000];
    for (int i = 0; i < sizeArray; i++)
    {
        temp[i] = ar[i];
    }
    clock_t start = clock();
    for (int i = 0; i < sizeArray - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < sizeArray; j++)
        {
            if (temp[j] < temp[min])
                min = j;
        }
        swap(temp[i], temp[min]);
    }
    clock_t end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Selection Sort took " << time_taken << " seconds to execute \n";
    cout << "Press Enter " << endl;

    cin.ignore();
    cin.get();
}

void insertionSort()
{
    clearTerminal();
    cout << "Insertion Sort is Running, please wait for it to finish!" << endl;
    long long temp[500000];
    for (int i = 0; i < sizeArray; i++)
    {
        temp[i] = ar[i];
    }
    clock_t start = clock();
    for (int i = 1; i < sizeArray; i++)
    {
        int key = temp[i];
        int j = i - 1;
        while (j >= 0 && temp[j] > key)
        {
            temp[j + 1] = temp[j];
            j--;
        }
        temp[j + 1] = key;
    }
    clock_t end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Insertion Sort took " << time_taken << " seconds to execute \n";
    cout << "Press Enter " << endl;
    cin.ignore();
    cin.get();
}

void allSort()
{
    bubbleSort();
    selectionSort();
    insertionSort();
}

void sort()
{
    string sortType;
    while (true)
    {
        if (sortIn == 1)
        {
            sortType = "Asending";
        }
        else if (sortIn == -1)
        {
            sortType = "Desending";
        }

        clearTerminal();
        cout << " Sorting in " << sortType << endl;
        cout << "0. All sorting method " << endl;
        cout << "1. Bubble Sort" << endl;
        cout << "2. Selection Sort" << endl;
        cout << "3. Insertion Sort" << endl;
        cout << "4. Merge Sort" << endl;
        cout << "5. Cycle sort" << endl;
        cout << "6. Quick Sort" << endl;
        cout << "7. Heap Sort" << endl;
        cout << "8. Radix Sort" << endl;
        cout << "9. Display Array" << endl;
        cout << "10. Back to menu" << endl;
        cout << " Enter your choice > ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 0:
            allSort();
            break;
        case 1:
            bubbleSort();
            break;
        case 2:
            selectionSort();
            break;
        case 3:
            insertionSort();
            break;
        case 4:
            //     mergeSort();
            break;
        case 5:
            //      cycleSort();
            break;
        case 6:
            //     quickSort();
            break;
        case 7:
            //    heapSort();
            break;
        case 8:
            //    radixSort();
            break;
        case 9:
            displayArray();
            break;
        case 10:
            clearTerminal();
            return;
        default:
            cout << "Invalid choice" << endl;
            cin.ignore();
            cin.get();
            clearTerminal();
            break;
        }
    }
}

void sortArray()
{
    while (true)
    {
        cout << "Select 1 for Ascending order" << endl;
        cout << "Select 2 for Descending order" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            sortIn = 1;
            clearTerminal();
            cout << "Ascending order selected" << endl;
            sort();
            return;
            break;
        case 2:
            sortIn = -1;
            clearTerminal();
            cout << "Descending order selected" << endl;
            sort();
            return;
            break;
        default:
            clearTerminal();
            break;
        }

        //      double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    }
}

int main()
{
    clearTerminal();
    char choice;

    while (1)
    {

        menu();
        cout << "\nEnter your choice > ";
        cin >> choice;
        switch (choice)
        {
        case '0':

            quit();
            break;
        case '1':
            randomData();
            break;
        case '2':
            displayArray();
            break;
        case '3':
            clearTerminal();
            sortArray();
            break;

        default:
            clearTerminal();
            cout << "Invalid choice" << endl;
            break;
        }
    }
    return 0;
}