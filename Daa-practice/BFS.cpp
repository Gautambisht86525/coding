#include<iostream>
#include<unordered_map>
using namespace std;
class graph{
    public : 
    unordered_map<int,vector<int>> g;
    void addEdge(int u,int v,bool dir){
        if(dir==1){ //directed
            g[u].push_back(v);
        }
        else{ //undirected
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    void BFS(int src){
        queue<int> q;
        unordered_map<int,bool> visited;
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            cout << front << ",";
            for(auto nbr : g[front]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }
        }
    }
};
int main(){
    graph g;
    g.addEdge(0,1,1);
     g.addEdge(0,2,1);
      g.addEdge(1,3,1);
       g.addEdge(2,8,1);
        g.addEdge(8,4,1);
         g.addEdge(4,5,1);
         g.addEdge(4,7,1);
         g.addEdge(5,6,1);
         g.addEdge(7,6,1);
    g.BFS(0);
    return 0;
}