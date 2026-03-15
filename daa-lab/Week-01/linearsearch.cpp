#include<iostream>
#include<vector>
using namespace std;

int linearSearch(vector<int> &arr,int n,int key){
int comparisons=0;
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            cout<<"Present"<<comparisons<<endl;
            return;
        }

    }
    cout<<"Not present"<<comparisons<<endl;
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

        int key;
        cin >> key;

        linearSearch(a, n, key);
    }

    return 0;
}
