#include<iostream>
#include<vector>
#include<climits>
using namespace std;

struct Edge{
    int src,dest,wt;
};

void bellmanford(vector<Edge> &edges,int V,int source){

    vector<int> dist(V,INT_MAX);

    dist[source]=0;

    for(int i=0;i<V-1;i++){
        
        for(auto nbr:edges){

            if(dist[nbr.src]!=INT_MAX && dist[nbr.src]+nbr.wt<dist[nbr.dest]){
                
                dist[nbr.dest]=dist[nbr.src]+nbr.wt;
            }
                      

        }

    }


    for(auto nbr:edges){

        if(dist[nbr.src]!=INT_MAX  &&  dist[nbr.src]+nbr.wt < dist[nbr.dest]){
            cout<<"Negative Weight cycle exists";
            return;
        }
    }

    cout<<"Shortest Distance";

    for(int i=0;i<V;i++){

        cout<<source+1<<"->"<<i+1<<"="<<dist[i]<<endl;
    }

}


int main(){
    int V;
    cin>>V;

    vector<Edge> edges;

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            int wt;
            cin>>wt;

            if(wt!=0){
                edges.push_back({i,j,wt});
            }
        }
    }

    int source;
    cin>>source;

    source--;

    bellmanford(edges,V,source);
    return 0;

}