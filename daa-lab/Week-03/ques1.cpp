#include<iostream>
#include<vector>
using namespace std;

void insertionsort(vector<int>&arr,int n){
    int comp=0;
    int shifts=0;
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;

        while(j>=0){
            comp++;
            if(arr[j]>=key){
                shifts++;
                arr[j+1]=arr[j];
                j--;
            }
            else{
                break;
            }
        }
        arr[j+1]=key;
        
    }

    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    cout<<endl;

    cout<<"comparisons"<<comp<<endl;
    cout<<"shifts"<<shifts<<endl;
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

        insertionsort(arr, n);
    }

    return 0;
}