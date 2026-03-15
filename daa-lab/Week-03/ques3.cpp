#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool hasDuplicate(vector<int> &a, int n)
{
    unordered_map<int, int> mp;

    for(int i = 0; i < n; i++)
    {
        if(mp[a[i]] == 1)
            return true;        

        mp[a[i]] = 1;
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