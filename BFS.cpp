#include<bits/stdc++.h>
using namespace std;
vector<int>graph[10001];
int visited_node[10001];
queue<int>que;
vector<int> BFS_Sequence;
void BFS(int node)
{
    visited_node[node]=1;
    que.push(node);
    BFS_Sequence.push_back(node);
    while(!que.empty())
    {
        int n=que.front();
        que.pop();
        for(int child:graph[n])
        {
            if(visited_node[child]==0)
            {
                visited_node[child]=1;
                que.push(child);
                BFS_Sequence.push_back(child);
            }
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
    BFS(1);   /// starting node;
    for(int val:BFS_Sequence)cout<<val<<" ";

    return 0;
}
