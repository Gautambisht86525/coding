#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &a, int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<int> L(n1), R(n2);

    for(int i = 0; i < n1; i++)
        L[i] = a[l + i];

    for(int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while(i < n1)
        a[k++] = L[i++];

    while(j < n2)
        a[k++] = R[j++];
}

void mergeSort(vector<int> &a, int l, int r)
{
    if(l < r)
    {
        int mid = (l + r) / 2;

        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);

        merge(a, l, mid, r);
    }
}

bool hasDuplicate(vector<int> &a, int n)
{
    mergeSort(a, 0, n - 1);     

    for(int i = 1; i < n; i++)
    {
        if(a[i] == a[i - 1])
            return true;
    }

    return false;
}

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int n;
        cin >> n;

        vector<int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        if(hasDuplicate(a, n))
            cout << "YES";
        else
            cout << "NO";

        cout << endl;
    }
}