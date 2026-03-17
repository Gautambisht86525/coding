#include<iostream>
#include<vector>
using namespace std;

void maxoccurence(int n,string s){
    vector<int>freq(26,0);

    for(int i=0;i<n;i++){
        freq[s[i]-'a']++;
    }

    int maxfreq=0;
    char ans;

    for(int i=0;i<n;i++){
        if(freq[i]>maxfreq){
            maxfreq=freq[i];
            ans=char(i+'a');
        }
    }

    if(maxfreq<=1){
        cout<<"No duplicate present"<<endl;
    }
    cout<<ans<<"-"<<maxfreq<<endl;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        maxoccurence(n, s);
    }

    return 0;
}