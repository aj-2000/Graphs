#include <bits/stdc++.h>
using namespace std;

int parent[100000];
int rank_arr[100000];
int n = 100000;

void makeSet()
{
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        rank_arr[i] = 0;
    }
}

int findPar(int node)
{
    if (node == parent[node])
    {
        return node;
    }
    return parent[node] = findPar(parent[node]);
}

void union_op(int u, int v)
{
    u = findPar(u);
    v = findPar(v);

    if (rank_arr[u] < rank_arr[v])
    {
        parent[u] = v;
    }
    else if (rank_arr[u] > rank_arr[v])
    {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank_arr[u]++;
    }
}

int main()
{
    makeSet();
    int m;
    cin >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        union_op(u, v);
    }

    if(findPar(2) != findPar(3)){
        cout << "Different Components";
    } else {
        cout << "Same Components";
    }

    return 0;
}