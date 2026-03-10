#include <iostream>
#include <vector>
using namespace std;

int countPairs(vector<int> &arr, int K)
{
    int n = arr.size();
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(abs(arr[i] - arr[j]) == K)
            {
                count++;
            }
        }
    }

    return count;
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

        int K;
        cin >> K;

        cout << countPairs(arr, K) << endl;
    }

    return 0;
}