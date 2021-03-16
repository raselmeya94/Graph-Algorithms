#include <bits/stdc++.h>
using namespace std;
vector<int> graph[10001];
int visited_node[10001];
int maxD, maxN;
void DFS(int node, int dis)
{
	visited_node[node] = 1;

	if (dis > maxD) maxD = dis, maxN = node;
	for (int child: graph[node])
	{
		if (visited_node[child] == 0)
		{
			DFS(child, dis + 1);
		}
	}
}

int main()
{
	int node, edge;
	cin >> node;
	edge = node - 1;
	while (edge--)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	maxD = -1;
	DFS(1, 0);

	for (int i = 1; i <= node; i++) visited_node[i] = 0;
	maxD = -1;
	DFS(maxN, 0);

	cout << maxD << endl;

}