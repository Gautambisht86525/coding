#include <bits/stdc++.h>
using namespace std;

long long compCount;
long long invCount;

void mergeArray(vector<int> &a, int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        compCount++;  

        if (L[i] <= R[j])
        {
            a[k++] = L[i++];
        }
        else
        {
            a[k++] = R[j++];
            invCount += (n1 - i);   
        }
    }

    while (i < n1)
        a[k++] = L[i++];

    while (j < n2)
        a[k++] = R[j++];
}

void mergeSort(vector<int> &a, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;

        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        mergeArray(a, l, mid, r);
    }
}

int main()
{
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
        invCount = 0;

        mergeSort(a, 0, n - 1);

        // sorted array
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;

        cout << "comparisons = " << compCount << endl;
        cout << "inversions = " << invCount << endl;
    }

    return 0;
}