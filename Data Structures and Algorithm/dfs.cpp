#include <iostream>
#include <fstream>
using namespace std;

#define UNDEFINED -1

void error(char * msg)
{
	cerr << "Error: " << msg << endl;
	exit(-1);
}

struct ListNode
{
	int cost; // the cost of this edge
	int vertex; // the destination of this edge
	ListNode * next;

	ListNode(int c, int v, ListNode * n)
		: cost(c), vertex(v), next(n)
	{
	}

	static void push(int c, int v, ListNode * & l)
	{
		l = new ListNode(c, v, l);
	}

	static void deleteList(ListNode * l)
	{
		if (l)
		{
			deleteList(l->next);
			delete l;
		}
	}

	friend ostream & operator << (ostream & out, ListNode * l)
	{
		if (l)
			out << " (" << l->vertex << "," << l->cost << ")" << l->next;
		return out;
	}

};

enum Color { WHITE, GRAY, BLACK };

struct Vertex
{
	int id;
	int distance;
	int previous;
	Color color;
	ListNode * adjacent;

	Vertex()
		: id(0), distance(UNDEFINED), previous(UNDEFINED), color(WHITE), adjacent(nullptr)
	{
	}

	friend ostream & operator << (ostream & out, Vertex & v)
	{
		out << "D:" << v.distance << " " << "P:" << v.previous << v.adjacent;
		return out;
	}

};

// Vertices are integers from 1 to N
// Store them in an adjacency list

const int WORD_LENGTH = 1024;

class Graph
{
	Vertex * vertices; // an array of Vertices
	int size;
public:

	Graph(char fileName[])
	{
		int value, src, dst, cost;
		ifstream in(fileName);
		if (in >> value) {
			size = value;
			vertices = new Vertex[size];
		}
		else
			error("file not found");
		for (int i = 0; i < size; ++i) // initialize the vertex array
		{
			Vertex &v = vertices[i];
			v.id = i;
			v.adjacent = nullptr;
		}
		for (; ; ) // read the values into the adjacency list
		{
			if (in >> src >> dst >> cost)
				addEdge(src, dst, cost);
			else
				break;
		}
		in.close();
	}

	friend ostream & operator << (ostream & out, Graph & g)
	{
		for (int i = 0; i < g.size; ++i)
			out << i << " " << g.vertices[i] << endl;
		return out;
	}

	void addEdge(int src, int dst, int cost)
	{
		ListNode::push(cost, dst, vertices[src].adjacent);
		//ListNode::push(cost, src, vertices[dst].adjacent);
	}

	int time;

	void DFS_VISIT(Vertex &v)
	{
		v.color = GRAY;
		v.distance = time++;
		for (ListNode * l = v.adjacent; l; l = l->next)
		{
			Vertex & u = vertices[l->vertex];
			if (u.color == WHITE)
			{
				u.previous = v.id;
				DFS_VISIT(u);
				u.color = BLACK;
			}
		}
	}

	void dfs()
	{
		time = 0;
		for (int i = 0; i < size; ++i)
		{
			Vertex & v = vertices[i];
			v.color = WHITE;
			v.previous = UNDEFINED;
		}
		for (int i = 0; i < size; ++i)
		{
			Vertex & v = vertices[i];
			if (v.color == WHITE)
				DFS_VISIT(v);
		}
	}

	void printPath()
	{
		int maxValue = 0;
		int maxIndex = 0;
		for (int i = 0; i < size; ++i)
		{
			Vertex & v = vertices[i];
			if (v.distance > maxValue)
			{
				maxValue = v.distance;
				maxIndex = i;
			}
		}
		for (int i = maxIndex; i != UNDEFINED; i = vertices[i].previous)
		{
			cout << i << endl;
		}
	}

	~Graph()
	{
		for (int i = 0; i < size; ++i)
			ListNode::deleteList(vertices[i].adjacent);
		delete[] vertices;
	}

};

//int main()
//{
//	Graph G("graph.txt");
//	G.dfs();
//	cout << G;
//	// G.printPath();
//	return 0;
//}