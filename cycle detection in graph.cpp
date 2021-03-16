#include <bits/stdc++.h>
using namespace std;
vector<int> graph[10001];
int visited_node[10001];
bool cycle_detection(int node, int par)
{
	visited_node[node] = 1;
	for (int child: graph[node])
	{
		if (visited_node[child] == 0)
		{
			if (cycle_detection(child, node) == true)
				return true;
		}
		else
		{
			if (child != par) return true;
		}
	}

	return false;
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

	if (cycle_detection(1, 1) == false) cout << "Cycle not found in this undirected graph." << endl;
	else cout << "Cycle found in this undirected graph." << endl;

}