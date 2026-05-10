#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int src,dest,wt;
};

int findParent(vector<int> &parent,int node){
    if(parent[node]==node){
        return node;
    }
    
    return parent[node]=findParent(parent,parent[node]);
}

void unionSet(int src,int dest,vector<int> &parent){

    src=findParent(parent,src);
    dest=findParent(parent,dest);

    parent[dest]=src;
}

void sortEdges(vector<Edge> &edges){
    for(int i=0;i<edges.size()-1;i++){
        for(int j=0;j<edges.size()-i-1;j++){

            if(edges[j].wt>edges[j+1].wt){
                swap(edges[j],edges[j+1]);
            }
        }
    }
}

int kruskalMST(vector<vector<int>>& graph,int V){

    vector<Edge> edges;

    
    for(int i = 0; i < V; i++){

        for(int j = i + 1; j < V; j++){

            if(graph[i][j] != 0){

                edges.push_back({i, j, graph[i][j]} );
            }
        }
    }

    sortEdges(edges);


    vector<int> parent(V);

    for(int i = 0; i < V; i++){

        parent[i] = i;
    }

    int minWeight = 0;

    for(auto edge : edges){

        int src = findParent(parent,edge.src);

        int dest = findParent(parent, edge.dest);

        if(src!=dest){
            unionSet(src,dest,parent);
            minWeight+=edge.wt;
        }
    }
    return minWeight;

}

int main(){

    int V;
    cin >> V;

    vector<vector<int>> graph( V,vector<int>(V));

    for(int i = 0; i < V; i++){

        for(int j = 0; j < V; j++){

            cin >> graph[i][j];
        }
    }

    int ans = kruskalMST(graph, V);

    cout << "Minimum Spanning Weight "
         << ans;

    return 0;
}