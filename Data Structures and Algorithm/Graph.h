#ifndef GRAPH_H
#define GRAPH_H

#include<fstream>
#include<iostream>
#include<string>
using namespace std;

#define DEFAULT_SIZE 1000
#define INF 1e9

struct Vertex {
	int id;
	int distance;
	Vertex *adjacent;
	Vertex() : id(-1), distance(INF), adjacent(nullptr) {}
	Vertex(int dst, int cost) : id(dst), distance(cost), adjacent(nullptr) {}

	bool operator < (const Vertex &other)
	{
		return distance < other.distance;
	}

	bool operator > (const Vertex &other)
	{
		return distance > other.distance;
	}

	static void delete_ln(Vertex *v)
	{
		if (v != nullptr)
		{
			delete_ln(v->adjacent);
			delete v;
		}
	}
};

class Graph
{
	void add_edge(int src, int dst, int cost)
	{
		if (vertices[src].adjacent == nullptr)
		{
			vertices[src].adjacent = new Vertex(dst, cost);
			return;
		}
		Vertex *p = &vertices[src];
		for (p; p->adjacent != nullptr; p = p->adjacent)
			if (p->id == dst) return;
		p->adjacent = new Vertex(dst, cost);
	}

public:
	Vertex *vertices;
	int size;

	Graph(): vertices(nullptr), size(0) {}

	Graph(const char *file)
	{
		ifstream in(file);
		in >> size;
		vertices = new Vertex[size];
		for (int i = 0; i < size; ++i)
			vertices[i].id = i;

		int src, dst, cost;
		while (in >> src >> dst >> cost)
		{
			add_edge(src, dst, cost);
			add_edge(dst, src, cost);
		}

		vertices[0].distance = 0;
		for (Vertex *v = vertices[0].adjacent; v != nullptr; v = v->adjacent)
			vertices[v->id].distance = v->distance;
	}

	Vertex& operator [] (int pos)
	{
		return vertices[pos];
	}

	~Graph()
	{
		for (int i = 0; i < size; ++i)
			Vertex::delete_ln(vertices[i].adjacent);
		delete[] vertices;
	}
};

#endif
