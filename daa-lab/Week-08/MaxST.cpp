#include<bits/stdc++.h>
using namespace std;

int maxST(vector<vector<int>>& graph,
          int V){

    vector<int> key(V, INT_MIN);
    vector<bool> mst(V, false);

    key[0] = 0;

    int maxWeight = 0;

    for(int i = 0; i < V; i++){

        int u = -1;

        
        for(int j = 0; j < V; j++){

            if(!mst[j] &&
              (u == -1 || key[j] > key[u])){

                u = j;
            }
        }

        mst[u] = true;

        maxWeight += key[u];

        
        for(int nbr = 0; nbr < V; nbr++){

            if(graph[u][nbr] != 0 &&
               !mst[nbr] &&
               graph[u][nbr] > key[nbr]){

                key[nbr] = graph[u][nbr];
            }
        }
    }

    return maxWeight;
}

int main(){

    int V;
    cin >> V;

    vector<vector<int>> graph(
        V,
        vector<int>(V)
    );

    
    for(int i = 0; i < V; i++){

        for(int j = 0; j < V; j++){

            cin >> graph[i][j];
        }
    }

    int ans = maxST(graph, V);

    cout << "Maximum Spanning Weight "
         << ans;

    return 0;
}