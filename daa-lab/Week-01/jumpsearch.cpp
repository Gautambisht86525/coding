#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int jumpSearch(vector<int> &arr, int n, int key, int &comp)
{
    int step = sqrt(n);
    int prev = 0;

    for(int i = step; i < n; i += step)
    {
        comp++;                 

        if(arr[i] >= key)
        {
            for(int j = prev; j <= i && j < n; j++)
            {
                comp++;        

                if(arr[j] == key)
                    return j;
            }
            return -1;
        }
        prev = i;
    }

    
    for(int j = prev; j < n; j++)
    {
        comp++;                 

        if(arr[j] == key)
            return j;
    }

    return -1;
}

int main()
{
    vector<int> arr = {1,3,5,7,9,11,13,15,17};

    int n = arr.size();
    int key = 11;

    int comparisons = 0;

    int result = jumpSearch(arr, n, key, comparisons);

    if(result != -1)
        cout << "Present " << comparisons;
    else
        cout << "Not Present " << comparisons;

    return 0;
}