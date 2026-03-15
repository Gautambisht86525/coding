#include<iostream>
#include<vector>
using namespace std;

int binarysearch(vector<int>&arr,int n,int key){
    int st=0;
    int end=n-1;
    int comparisons=0;
     
    while(st<=end){
        int mid=st+(end-st)/2;
        comparisons++;

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
    return -comparisons;

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

        int result=binarysearch(arr,n,key);

        if(result!=-1){
            cout<<"ELement found at index"<<result<<endl;
        }
        else{
            cout<<"Element not found";
        }


    }
    return 0;
}