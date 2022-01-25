#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;
int ar[50000], n;
double t1, t2, t3;
void menu()
{
    cout << "\t\tMENU " << endl;
    cout << "0. Quit" << endl;
    cout << "1. n Random numbers=>Array" << endl;
    cout << "2. Display the Array" << endl;
    cout << "3. Sort the array in Ascending Order by using Max-Heap Sort technique" << endl;
    cout << "4. Sort the array in Descending Order by using any algorithm" << endl;
    cout << "5. Time Complexity to sort ascending of random data" << endl;
    cout << "6. Time Complexity to sort ascending of data already sorted in ascending order" << endl;
    cout << "7. Time Complexity to sort ascending of data already sorted in descending order" << endl;
    cout << "8. Time Complexity to sort ascending of all cases in tabular form for values n = 5000 to 50000" << endl;
    cout << "9. Extract largest element" << endl;
    cout << "10. Replace a value at a node with a new value" << endl;
    cout << "11. Insert a new element" << endl;
    cout << "12. Delete an element" << endl;
}
void quit()
{
    exit(0);
}
void input()
{
    cout << "Enter size of array ";
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        ar[i] = rand() % 100;
    }
}
void input_table()
{
    for (int i = 0; i < n; ++i)
    {
        ar[i] = rand();
    }
}
void display()
{
    cout << endl;
    cout << "Array is:" << endl;
    cout << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << ar[i] << endl;
    }
}
void max_heapify(int ar[], int n, int i)
{
    int lar = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && ar[l] > ar[lar])
        lar = l;
    if (r < n && ar[r] > ar[lar])
        lar = r;
    if (lar != i)
    {
        swap(ar[i], ar[lar]);
        max_heapify(ar, n, lar);
    }
}
void sort(int ar[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        max_heapify(ar, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(ar[0], ar[i]);
        max_heapify(ar, i, 0);
    }
}
void sort1(int ar[], int n)
{
    t1 = clock();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        max_heapify(ar, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(ar[0], ar[i]);
        max_heapify(ar, i, 0);
    }
    t1 = (clock() - t1) / CLOCKS_PER_SEC;
}
void sort2(int ar[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ar[j] < ar[j + 1])
                swap(ar[j], ar[j + 1]);
        }
    }
}
void time2()
{
    sort(ar, n);
    t2 = clock();
    sort(ar, n);
    t2 = (clock() - t2) / CLOCKS_PER_SEC;
}
void time3()
{
    sort2(ar, n);
    t3 = clock();
    sort(ar, n);
    t3 = (clock() - t3) / CLOCKS_PER_SEC;
}
int main()
{
    int ch;
    while (true)
    {
        menu();
        cout << endl;
        cout << "Enter choice" << endl;
        cin >> ch;
        switch (ch)
        {
        case 0:
            quit();
            break;
        case 1:
        {
            input();
            cout << "Array of size " << n << " created" << endl;
            cout << endl;
        }
        break;
        case 2:
            display();
            break;
        case 3:
        {
            sort1(ar, n);
            cout << "Array sorted in ascending order using Max-Heap sort algorithm" << endl;
            cout << endl;
        }
        break;
        case 4:
        {
            sort2(ar, n);
            cout << "Array sorted in descending order" << endl;
            cout << endl;
        }
        break;
        case 5:
        {
            cout << "Time Complexity to sort ascending of random data is " << t1 << endl;
            cout << endl;
            t1 = 0;
        }
        break;
        case 6:
        {
            time2();
            cout << "Time Complexity to sort ascending of data already sorted in ascending order is " << t2 << endl;
            cout << endl;
        }
        break;
        case 7:
        {
            time3();
            cout << "Time Complexity to sort ascending of data already sorted in descending order is " << t3 << endl;
            cout << endl;
        }
        break;
        case 8:
        {
            cout << "Input\tRandom to Ascending\tAscending to Ascending\tDescending to Ascending" << endl;
            cout << "-------------------------------------------------------------------------------------" << endl;
            for (int i = 5000; i <= 50000; i += 5000)
            {
                n = i;
                input_table();
                sort1(ar, n);
                time2();
                time3();
                cout << fixed;
                cout << setprecision(5);
                cout << i << "\t\t" << t1 << "\t\t        " << t2 << "\t\t         " << t3 << endl;
                t1 = t2 = t3 = 0;
            }
            cout << endl;
        }
        break;
        case 9:
        {
            sort(ar, n);
            cout << "Largest element is " << ar[0] << endl;
        }
        break;
        case 10:
        {
            int ind, num;
            cout << "Enter index number at which value to be replaced ";
            cin >> ind;
            cout << "Enter new number ";
            cin >> num;
            ar[ind] = num;
            cout << "Value replaced with new value" << endl;
        }
        break;
        case 11:
        {
            int n1;
            cout << "Enter number to be inserted to heap ";
            cin >> n1;
            n = n + 1;
            ar[n - 1] = n1;
            cout << "Number inserted" << endl;
            sort(ar, n);
        }
        break;
        case 12:
        {
            int ind2;
            cout << "Enter index number at which number to be deleted ";
            cin >> ind2;
            int last = ar[n - 1];
            ar[ind2] = last;
            n = n - 1;
            cout << "Value deleted" << endl;
        }
        break;
        default:
            cout << "Invalid choice, try again" << endl;
            cout << endl;
        }
    }
}