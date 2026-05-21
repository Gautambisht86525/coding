#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
unordered_map<int,vector<int>> convert_to_list(vector<vector<int>>&adjMat){
    unordered_map<int,vector<int>> adjList;

    for(int i=0;i<adjMat.size();i++){
        for(int j=0;j<adjMat[i].size();j++){
            if(adjMat[i][j]==1){
                adjList[i].push_back(j);
            }
        }
    }
     return adjList;
}

bool dfs(int node,unordered_map<int,vector<int>> &adjList,vector<bool> &visited,vector<bool> &path){
    visited[node]=true;
    path[node]=true;

    for(auto nbr :adjList[node]){
        if(!visited[node]){
            if(dfs(nbr,adjList,visited,path))
            return true;
        }

        else if(path[nbr]){
            return true;
        }
    }

    path[node]=false;
    return false;
}


bool isCycle(int V,unordered_map<int,vector<int>> &adjList){
    vector<bool> visited(V,false);
    vector<bool> path(V,false);

    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(dfs(i,adjList,visited,path))
            return true;
        }
    }
    return false;
}

int main(){
    int V;
    cin>>V;

    vector<vector<int>> adjMat(V,vector<int>(V));

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin>>adjMat[i][j];
        }
    }

    unordered_map<int,vector<int>> adjList=convert_to_list(adjMat);
    if(isCycle(V,adjList)){
        cout<<"Cycle exists";
    }
    else{
        cout<<"NO cycle exists";
    }
    return 0;
}