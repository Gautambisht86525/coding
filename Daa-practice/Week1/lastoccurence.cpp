#include <iostream>
using namespace std;

int firstOccurrence(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
        {
            ans = mid;        // store index
            high = mid - 1;   // move left
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
    int arr[] = {1,2,2,2,3,4};
    int n = 6;
    int key = 2;

    int result = firstOccurrence(arr, n, key);

    if(result != -1)
        cout << "First occurrence at index: " << result;
    else
        cout << "Element not found";

    return 0;
}