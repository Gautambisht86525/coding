#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void printPath(int node,vector<int> &parent){
if(node==-1){
    return;
}
printPath(parent[node],parent);
cout<<node<<" ";

}

void dijkstra(vector<vector<int>> &graph,int src){

    int V=graph.size();

    vector<int> dist(V,INT_MAX);
    vector<bool> visited(V,false);
    vector<int> parent(V,-1);

    dist[src]=0;

    for(int i=0;i<V-1;i++){

        int u=-1;

        for(int j=0;j<V;j++){
            if(!visited[j] && (u==-1 || dist[j]<dist[u])){
                u=j;
            }
        }

        visited[u]=true;

    


    for(int nbr=0;nbr<V;nbr++){
        if(graph[u][nbr]!=0 && !visited[nbr] && dist[u]!=INT_MAX && dist[u]+graph[u][nbr]<dist[nbr]){
            dist[nbr]=dist[u]+graph[u][nbr];
            parent[nbr]=u;

        }
    }


}

cout<<"Vertex\tDistance\tPath\n";
for(int i=0;i<V;i++){
    cout<<i<<"\t"<<dist[i];

    printPath(i,parent);
}

}

int main(){
    int V;
    cin>>V;

    vector<vector<int>> graph(V,vector<int>(V));

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin>>graph[i][j];

        }
    }

    int source;
    cin>> source;

    dijkstra(graph,source);

    return 0;
}