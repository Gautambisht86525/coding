#include<iostream>
#include<vector>
using namespace std;

void selectionsort(vector<int>&arr,int n){
    int comp=0;
    int swapc=0;
    for(int i=0;i<n;i++){
        int minIndex=i;
    
    for(int j=i+1;j<n;j++){
        comp++;
        if(arr[j]<arr[minIndex]){
            minIndex=j;
        }
    }

        if(minIndex!=i){
            swap(arr[i],arr[minIndex]);
            swapc++;
        }
    }
  for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "comparisons = " << comp << endl;
    cout << "swaps = " << swapc << endl;
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
            cin >> arr[i];

        selectionsort(arr, n);
    }

    return 0;
}