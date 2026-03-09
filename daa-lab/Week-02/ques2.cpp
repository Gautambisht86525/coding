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
                high = mid - 1;   // move left
            else
                low = mid + 1;    // move right
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
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter sorted array elements:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "Enter key: ";
    cin >> key;

    int first = binarySearch(arr, key, true);
    int last = binarySearch(arr, key, false);

    if(first == -1)
    {
        cout << "Key not present in array";
    }
    else
    {
        int copies = last - first + 1;

        cout << "Key found\n";
        cout << "First Occurrence Index = " << first << endl;
        cout << "Last Occurrence Index = " << last << endl;
        cout << "Number of Copies = " << copies << endl;
    }

    return 0;
}