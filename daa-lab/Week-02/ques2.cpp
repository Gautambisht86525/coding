#include<iostream>
#include<vector>
using namespace std;

void occurrence(vector<int>&arr,int n){
    bool found=false;
    for(int i=n-1;i>=2 && !found;i++){
        int st=0;
        int end=i-1;

        while(st<=end){
            int sum=arr[st]+arr[end];
            if(sum==arr[i]){
                cout<<st<<end<<i<<endl;
                break;
            }
            else if(sum<arr[i]){
                st++;
            }
            else{
                end--;
            }
        }
        if(!found){
            cout<<"No sequence found"<<endl;
        }
        
    }
    
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

        occurrence(arr,n);
    }
    return 0;
}