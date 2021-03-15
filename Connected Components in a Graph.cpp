#include<bits/stdc++.h>
using namespace std;
vector<int> graph[100001];
int  visited_node[100001];

void DFS(int node )
{

    if(!visited_node[node])
    {
        visited_node[node]=1;

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
    int cnt=0;
    for(int i=1; i<=node; i++){
    	if(!visited_node[i]){
    		cnt++;
    		DFS(i);
    	}
    }
    cout<<cnt<<endl;



}
