#include<iostream>
#include<vector>
using namespace std;

int firstoccurence(vector<int>&arr,int n,int key){
    int st=0;
    int end=n-1;
    int ans=-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(arr[mid]==key){
            return ans;
            end=mid-1;
        }
        else if(arr[mid]<key){
            st=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return ans;
}

int lastoccurence(vector<int>&arr,int n,int key){
    int st=0;
    int end=n-1;
    int ans=-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(arr[mid]==key){
            return ans;
            st=mid+1;
        }
        else if(arr[mid]<key){
            st=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return ans;
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

        int first=firstoccurence(arr,n,key);

        if(first==-1){
             cout<<"Key not present"<<endl;
        }
        else{
           int last=lastoccurence(arr,n,key);
            cout<<key<<last-first+1<<endl;
        }
    }
    return 0;
}