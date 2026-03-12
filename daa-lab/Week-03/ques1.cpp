#include <iostream>
using namespace std;

void insertionSort(int a[], int n)
{
    int comp = 0;
    int shift = 0;

    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0)
        {
            comp++;     // comparison

            if (a[j] > key)
            {
                a[j + 1] = a[j];
                shift++;   // shift
                j--;
            }
            else
                break;
        }

        a[j + 1] = key;
    }

    // print sorted array
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    cout << "comparisons = " << comp << endl;
    cout << "shifts = " << shift << endl;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        int a[1000];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        insertionSort(a, n);
    }

    return 0;
}