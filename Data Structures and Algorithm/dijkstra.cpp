#include"Graph.h"
#include"PriorityQueue.h"
#include<stack>

struct Table {
	int *table;
	int capacity;
	Table(int cap, int default_val) : table(new int[cap]), capacity(cap)
	{
		for (int i = 0; i < cap; ++i)
			table[i] = default_val;
	}
	int& operator [] (int pos)
	{
		return table[pos];
	}
	~Table()
	{
		delete[] table;
	}
};

void dijkstra(Graph &g, Vertex &v, Table &dist, Table &prev)
// O((E + N)lgN), E is the number of edges
// if considering the worst case that E = N(N - 1)/2,
// then the time complexity is O(N^2 lgN).
// Analysis:
// The first for loop has time complexity O(NlgN);
// the number of while loop execution is O(N);
// the total number of the second for loop execution is O(E);
// both extractMin() and decreaseKey() have complexity O(lgN);
// so combining all of them, the overall time complexity is O((E + N)lgN).
{
	dist[0] = 0;
	PriorityQueue<Vertex> Q(g.size);
	for (int i = 0; i < g.size; ++i)
		Q.insert(g[i]);
	while (!Q.isEmpty())
	{
		Vertex *u = Q.extractMin();
		for (Vertex *v = u->adjacent; v != nullptr; v = v->adjacent)
		{
			if (dist[v->id] > dist[u->id] + v->distance)
			{
				dist[v->id] = dist[u->id] + v->distance;
				prev[v->id] = u->id;
				Q[v->id]->distance = dist[v->id];
				Q.decreaseKey(v->id);
			}
		}
	}
}

int main()
{
	Graph g("graph.txt");
	Table dist(g.size, INF), prev(g.size, -1);
	Vertex start(0, 0);
	dijkstra(g, start, dist, prev);
	stack<int> path;
	for (int i = 1; i < g.size; i++)
	{
		cout << i << " Path: ";
		int j = i;
		path.push(i);
		while (prev[j] != -1)
		{
			j = prev[j];
			path.push(j);
		}
		while (path.size() > 1)
		{
			cout << path.top() << "-";
			path.pop();
		}
		cout << path.top();
		path.pop();
		cout << " Cost: " << dist[i] << endl;
	}
	return 0;
}
