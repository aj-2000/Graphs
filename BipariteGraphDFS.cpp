#include <bits/stdc++.h>
using namespace std;

bool bipartiteDFS(int node, vector<int> adj[], int color[]){
    for(auto it : adj[node]){
        if(color[it] == -1){
            color[it] = 1 - color[node];
            if(!bipartiteDFS(it, adj, color)){
                return false;
            }
        } else if(color[it] == color[node]) return false;
    }
}

bool checkBipartite(vector<int> adj[], int n){
    int color[n];
    memset(color, -1, sizeof color);
    for(int i = 0; i < n; i++){
        if(color[i] == -1){
            color[i] = 1;
            if(!bipartiteDFS(i, adj, color)){
                return false;
            }
        }
    }
    return true;
}

void addedge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    vector<int> adj[6];
    addedge(adj, 0, 1);
    addedge(adj, 1, 2);
    addedge(adj, 1, 4);
    addedge(adj, 1, 5);
    addedge(adj, 2, 3);
    addedge(adj, 3, 4);
    addedge(adj, 3, 5);

    if(checkBipartite(adj, 6)){
        cout << "It is a Bipartite Graph" << endl;
    } else {
        cout << "It is not a Bipartite Graph" << endl;
    }
    return 0;
}