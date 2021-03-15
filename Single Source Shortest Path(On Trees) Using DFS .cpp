#include<bits/stdc++.h>
using namespace std;
vector<int> graph[100];
int  visited_node[100];
int distance_arr[100];
void DFS(int node, int dis )
{
    visited_node[node]=1;
    distance_arr[node]=dis;

    for(int i=0; i<graph[node].size(); i++)
    {
        if(visited_node[graph[node][i]] == 0)
        {

            DFS(graph[node][i], distance_arr[node] +1);
        }
    }
}
int main()
{

    int node,edge;
    cin>>node>>edge;

    while(edge--)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    DFS(1,0); // root node =1; root node distance=0;
    for(int i=1; i<=node; i++)cout<<distance_arr[i]<<" ";
}
