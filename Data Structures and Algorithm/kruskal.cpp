#include<algorithm>
#include<fstream>
#include<iostream>
#include<vector>
using namespace std;

struct vertex {
	int id, parent_id;
	vertex(): id(-1), parent_id(-1) {}
};

struct edge {
	int v1, v2, w;
	edge() : v1(-1), v2(-1), w(-1) {}
	edge(int v1_val, int v2_val, int w_val)
		:v1(v1_val), v2(v2_val), w(w_val) {}
};

struct graph {
	vector<edge> edges;
	int size;
	graph(const char *file)
	{
		ifstream in(file);
		in >> size;
		int t1, t2, t3;
		while (in >> t1 >> t2 >> t3)
			edges.push_back(edge(t1, t2, t3));
	}
};

int compare(const edge &e1, const edge &e2)
// O(1)
{
	return e1.w < e2.w;
}

int find_source(vertex * vertices, int id)
// O(1)
{
	if (vertices[id].parent_id == -1) return id;
	else
	{
		vertices[id].parent_id = find_source(vertices, vertices[id].parent_id);
		return vertices[id].parent_id;
	}
}

vector<edge> kruskal(graph &g)
// O(|E|lg|V|)
{
	int edge_count = 0;
	vector<edge> result;
	vertex *vertices = new vertex[g.size];
	for (int i = 0; i < g.size; ++i)
		vertices[i].id = i;
	sort(g.edges.begin(), g.edges.end(), compare);
	for (int i = 0; i < g.edges.size(); ++i)
	{
		if (find_source(vertices, g.edges[i].v1) !=
			find_source(vertices, g.edges[i].v2))
		{
			edge_count += 1;
			result.push_back(g.edges[i]);
			vertices[find_source(vertices, g.edges[i].v2)].parent_id = g.edges[i].v1;
		}
		if (edge_count >= g.size - 1) break;
	}
	delete[] vertices;
	return result;
}

int main()
{
	graph g("graph.txt");
	vector<edge> result = kruskal(g);
	int cost = 0;
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i].v1 << " - " << result[i].v2 << " : " << result[i].w << endl;
		cost += result[i].w;
	}
	cout << "Cost: " << cost << endl;
	return 0;
}
