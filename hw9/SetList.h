template <typename T>
struct ListNode{
	T info;
	ListNode<T>* next;
	ListNode(T new_info) :info(new_info), next(nullptr) {}
	~ListNode() {}
};

template <typename T>
class SetList
{
private:
	ListNode<T>* head;
public:
	struct iterator
	{
		typedef std::forward_iterator_tag iterator_category;
		typedef iterator self_type;
		typedef ListNode<T> value_type;
		typedef ListNode<T>& reference;
		typedef ListNode<T>* pointer;
		typedef ptrdiff_t difference_type;
	private:
		pointer ibuf;
	public:
		iterator(pointer ptr) : ibuf(ptr) {}
		self_type operator ++ () { ibuf = ibuf->next; return *this; }
		self_type operator ++ (int postfix)
		{ self_type cpy = *this; ibuf = ibuf->next; return cpy; }
		reference operator * () { return *ibuf; }
		pointer operator -> () { return ibuf; }
		bool operator == (const self_type& rhs) const
		{ return ibuf == rhs.ibuf; }
		bool operator != (const self_type& rhs) const
		{ return ibuf != rhs.ibuf; }
	};

	SetList() : head() {}
	iterator begin() { return iterator(head); }
	iterator end() { return iterator(nullptr); }
	iterator find(const T& val)
	{
		ListNode<T>* p;
		for (p = head; p; p = p->next)
		{
			if (p->info == val) {
				break;
			}
		}
			
		return iterator(p);
	}
	void insert(T data)
	{
		if (head == nullptr)
		{
			head = new ListNode<T>(data);
			return;
		}
		ListNode<T>* p;
		for (p = head; p->next; p = p->next);
		p->next = new ListNode<T>(data);
	}
	void delete_listnode(ListNode<T>* LN)
	{
		if (!LN) return;
		if (LN->next) delete_listnode(LN->next);
		delete LN;
	}
	~SetList()
	{
		delete_listnode(head);
	}
};