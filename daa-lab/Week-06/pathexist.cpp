#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
 
unordered_map<int,vector<int>>convert_mat_to_list(vector<vector<int>> &adjMat){
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


bool pathFinder(int src,int dest,unordered_map<int,vector<int>>&adjList,vector<bool>&visited){
    if(src==dest){
        return true;
    }
    visited[src]=true;

    for(auto nbr:adjList[src]){
        if(!visited[nbr]){
            if(pathFinder(nbr,dest,adjList,visited)){
                return true;
            }
        }
    }
    return false;
}


int main(){
    int V;
    cout<<"ENter number of vertices"<<endl;
    cin>>V;

    vector<vector<int>> adjMat(V,vector<int>(V));

    cout<<"ENter adjacency matrix";
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
             cin>>adjMat[i][j];
        }
    }


    unordered_map<int,vector<int>>adjList=convert_mat_to_list(adjMat);
      int src, dest;
    cout << "Enter source: ";
    cin >> src;
    cout << "Enter destination: ";
    cin >> dest;

    vector<bool> visited(V, false);

    if(pathFinder(src, dest, adjList, visited)) {
        cout << "Yesss (Path exists)" << endl;
    } else {
        cout << "Nooo (No path exists)" << endl;
    }

    return 0;

}
