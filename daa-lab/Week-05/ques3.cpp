#include <iostream>
#include <vector>
using namespace std;

void commonElements(vector<int> &a, vector<int> &b, int m, int n)
{
    int i = 0, j = 0;

    while (i < m && j < n)
    {
        if (a[i] == b[j])
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
        else if (a[i] < b[j])
            i++;
        else
            j++;
    }
}

int main()
{
    int m, n;

    cin >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i];

    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];

    commonElements(a, b, m, n);

    return 0;
}