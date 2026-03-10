#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int key, bool findFirst)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = -1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
        {
            ans = mid;

            if(findFirst)
                high = mid - 1;
            else
                low = mid + 1;
        }
        else if(arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);

        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int key;
        cin >> key;

        int first = binarySearch(arr, key, true);
        int last = binarySearch(arr, key, false);

        if(first == -1)
        {
            cout << "Key not present" << endl;
        }
        else
        {
            int copies = last - first + 1;
            cout << key << " - " << copies << endl;
        }
    }

    return 0;
}