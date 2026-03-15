#include <iostream>
#include <cmath>
using namespace std;

int jumpSearch(int arr[], int n, int key)
{
    int step = sqrt(n);
    int prev = 0;

    for(int i = step; i < n; i += step)
    {
        if(arr[i] >= key)
        {
            for(int j = prev; j <= i; j++)
            {
                if(arr[j] == key)
                    return j;
            }
        }
        prev = i;
    }

    // search in last block
    for(int j = prev; j < n; j++)
    {
        if(arr[j] == key)
            return j;
    }

    return -1;
}

int main()
{
    int arr[] = {1,3,5,7,9,11,13,15,17};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 11;

    int result = jumpSearch(arr, n, key);

    if(result != -1)
        cout << "Element found at index " << result;
    else
        cout << "Element not found";

    return 0;
}