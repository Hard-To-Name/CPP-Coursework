#include"Shape.h"

class Picture
{
private:
	struct ShapeListNode
	{
		Shape* s;
		ShapeListNode* p;
		ShapeListNode(Shape* s_val, ShapeListNode* p_val)
			: s(s_val), p(p_val)
		{}
	};
	ShapeListNode* head;
public:
	Picture()
		: head(0)
	{}
	void add(Shape *sp)
	{
		head = new ShapeListNode(sp, head);
	}
	void drawAll()
	{
		for (ShapeListNode *ptr = head; ptr != nullptr; ptr = ptr->p)
		{
			ptr->s->draw();
			cout << endl;
		}
	}
	double totalArea()
	{
		double total = 0.0;
		for (ShapeListNode *ptr = head; ptr != nullptr; ptr = ptr->p)
			total += ptr->s->area();
		return total;
	}
	void delete_list(ShapeListNode *head)
	{
		if (!head)
		{
			delete_list(head->p);
			delete head;
		}
	}
	~Picture()
	{
		delete_list(head);
	}
};