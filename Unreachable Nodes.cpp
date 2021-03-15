#include<bits/stdc++.h>
using namespace std;
vector<int> graph[100];
int  visited_node[100];
int cnt=0;
void DFS(int node )
{

    if(!visited_node[node])
    {
        visited_node[node]=1;
        cnt++;
        for(int i=0; i<graph[node].size(); i++)
        {
            if(!visited_node[graph[node][i]])
            {

                DFS(graph[node][i]);
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
    int x;   // given that , root node=x;
    cin>>x;
    DFS(x);
 cout<<node-cnt<<endl;



}
