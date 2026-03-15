#include<iostream>
#include<vector>
using namespace std;

int simplebinarysearch(vector<int>&arr,int n,int key){
    int st=0;
    int end=n-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            st=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;
}

int main(){

    int T;
    cin>>T;

    while(T--){

        int n;
        cin>>n;

        vector<int> arr(n);

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int key;
        cin>>key;

        int result= simplebinarysearch(arr,n,key);

        if(result!=-1){
            cout<<"Element found at index"<<result;
        }
        else{
            cout<<"Element not found ";
        }
    }
    return 0;
}