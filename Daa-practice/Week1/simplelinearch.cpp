#include<iostream>
#include<vector>
using namespace std;

int simplelinearsearch(vector<int> &arr,int n,int key){

    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }

    }
    return -1;
}


int main(){
    int T;
    cin >> T;                

    while(T--)
    {
        int n;
        cin >> n;            

        vector<int> arr(n);

        for(int i = 0; i < n; i++)
            cin >> arr[i];     

        int key;
        cin >> key;        

        int result = simplelinearsearch(arr,n, key);

        if(result == -1)
            cout << "Not Present" << endl;
        else
            cout << "Present at index " << result << endl;
    }

    return 0;
}