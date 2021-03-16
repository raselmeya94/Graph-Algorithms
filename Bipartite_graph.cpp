#include <bits/stdc++.h>
using namespace std;
vector<int> graph[10001];
int visited_node[10001];
int color_graph[10001];
bool isBipartite(int node, int color)
{
	visited_node[node] = 1;
	color_graph[node] = color;
	for (int child: graph[node])
	{
		if (visited_node[child] == 0)
		{
			if (isBipartite(child, (color ^ 1)) == false)
			{
				return false;
			}
		}
		else
		{
			if (color_graph[node] == color_graph[child])
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	int node, edge;
	cin >> node >> edge;

	while (edge--)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int color = 0;
	if (isBipartite(1, color) == true) cout << "This is bipartite graph." << endl;
	else cout << "Opps,, it's not bipartite graph." << endl;

}