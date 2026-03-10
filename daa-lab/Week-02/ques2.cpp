#include <iostream>
#include <vector>
using namespace std;

void findSequence(vector<int> &arr)
{
    int n = arr.size();
    bool found = false;

    for(int k = n - 1; k >= 0; k--)
    {
        int i = 0;
        int j = k - 1;

        while(i < j)
        {
            int sum = arr[i] + arr[j];

            if(sum == arr[k])
            {
                cout << i << "," << j << "," << k << endl;
                found = true;
                return;
            }
            else if(sum < arr[k])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
    }

    if(!found)
    {
        cout << "No sequence found" << endl;
    }
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

        findSequence(arr);
    }

    return 0;
}