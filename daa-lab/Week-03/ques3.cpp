#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool hasDuplicate(vector<int> &a, int n)
{
    sort(a.begin(), a.end());   // O(n log n)

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
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}