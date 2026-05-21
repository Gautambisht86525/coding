#include <bits/stdc++.h>
using namespace std;

long long compCount = 0;
long long swapCount = 0;

int partitionRandom(vector<int> &a, int low, int high)
{
    
    int pivotIndex = low + rand() % (high - low + 1);

    swap(a[pivotIndex], a[high]);
    swapCount++;

    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        compCount++;   

        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
            swapCount++;
        }
    }

    swap(a[i + 1], a[high]);
    swapCount++;

    return i + 1;
}

void quickSort(vector<int> &a, int low, int high)
{
    if (low < high)
    {
        int p = partitionRandom(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main()
{
    srand(time(0));

    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        compCount = 0;
        swapCount = 0;

        quickSort(a, 0, n - 1);

        // sorted array
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;

        cout << "comparisons = " << compCount << endl;
        cout << "swaps = " << swapCount << endl;
    }
}