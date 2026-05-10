#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int shortestpath(int V,vector<vector<int>> &graph,int src,int dest,int k){

    vector<vector<int>>dp(k+1,vector<int>(V,INT_MAX));

 
    dp[0][src]=0;

    for(int edges=1;edges<=k;edges++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                
                if(graph[i][j]!=0  && dp[edges-1][i]!=INT_MAX){
                    dp[edges][i]=min(dp[edges][j],dp[edges][i]+graph[i][j]);
                }
            }
        }
    }

    if(dp[k][dest]==INT_MAX){
        return -1;
    }

    return dp[k][dest];
}

int main() {

    int V;
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

      for(int i = 0; i < V; i++) {

        for(int j = 0; j < V; j++) {

            cin >> graph[i][j];
        }
    }

      int src, dest, k;

    cin >> src >> dest;
    cin >> k;

    src--;
    dest--;

    int ans = shortestpath(V, graph, src, dest, k);

    if(ans == -1)
        cout << "No Path Exists";
    else
        cout << "Shortest Path Weight = " << ans;

    return 0;
}