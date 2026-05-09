#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

unordered_map<int,vector<int>>convert_to_list(vector<vector<int>>&adjMat){
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

bool isBipartite(int V,unordered_map<int,vector<int>> &adjList){
    vector<int> color(V,-1);

    for(int i=0;i<V;i++){
        if(color[i]==-1){
            queue<int>q;
            q.push(i);
            color[i]=0;
        

        while(!q.empty()){
            int front =q.front();
            q.pop();

            for(auto nbr:adjList[front]){
                if(color[nbr]==-1){
                    color[nbr]=1-color[front];
                    q.push(nbr);
                }
                else if(color[nbr]==color[front]){
                    return false;
                }

                }
            }


        }
    }
    return true;
}


int main(){
    int V;
    cin>>V;

    vector<vector<int>>adjMat(V,vector<int>(V));

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin>>adjMat[i][j];
        }
    }

    unordered_map<int,vector<int>> adjList = convert_to_list(adjMat);

     if(isBipartite(V, adjList)){
        cout << "Yes";
    }
    else{
        cout << "No";
    }

    return 0;
}