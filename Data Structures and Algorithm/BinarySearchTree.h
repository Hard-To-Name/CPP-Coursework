#include<iostream>
using namespace std;

template <typename KeyType, typename ElementType>
class BinarySearchTree
{
	class TreeNode
	{
	public:
		KeyType key;
		ElementType info;
		TreeNode *left, *right;

		TreeNode(KeyType newKey, ElementType newInfo, TreeNode *l, TreeNode *r)
			:key(newKey), info(newInfo), left(l), right(r) {}

		static TreeNode *newNode(KeyType k, ElementType e, TreeNode *l, TreeNode *r)
		{
			return new TreeNode(k, e, l, r);
		}

		static TreeNode *copy(TreeNode *tn)
		{
			if (tn == nullptr) return nullptr;
			return newNode(tn->key, tn->info, copy(tn->left), copy(tn->right));
		}

		static void swap(TreeNode &t1, TreeNode &t2)
		{
			KeyType tempk = t1.key;
			ElementType tempe = t1.info;
			t1.key = t2.key;
			t1.info = t2.info;
			t2.key = tempk;
			t2.info = tempe;
		}

		static void length_count(int *l_c, TreeNode *tn)
		{
			if (tn == nullptr) return;
			l_c[tn->key.size()] += 1;
			length_count(l_c, tn->left);
			length_count(l_c, tn->right);
		}

		static TreeNode *insert(KeyType &k, ElementType &e, TreeNode *t)
		// O(lgN)
		{
			if (!t) return newNode(k, e, nullptr, nullptr);
			if (k < t->key) t->left = insert(k, e, t->left);
			else if (k > t->key) t->right = insert(k, e, t->right);
			else t->info = e;
			return t;
		}

		static TreeNode *find(KeyType &k, TreeNode *t)
		// O(lgN)
		{
			if (!t) return nullptr;
			if (k == t->key) return t;
			if (k < t->key) return find(k, t->left);
			else return find(k, t->right);
		}

		static TreeNode *remove(KeyType &k, TreeNode *t)
		// O(lgN)
		{
			if (t == nullptr) return t;
			if (k < t->key) t->left = remove(k, t->left);
			else if (k > t->key) t->right = remove(k, t->right);
			else
			{
				if (t->left == nullptr)
				{
					TreeNode *temp = t->right;
					deleteNode(t);
					return temp;
				}
				if (t->right == nullptr)
				{
					TreeNode *temp = t->left;
					deleteNode(t);
					return temp;
				}
				TreeNode *temp = t->right;
				while (temp->left != nullptr) temp = temp->left;
				swap(*t, *temp);
				t->right = remove(temp->key, t->right);
			}
			return t;
		}

		static void print(ostream &out, TreeNode *t)
		{
			if (t != nullptr)
			{
				out << '[';
				print(out, t->left);
				out << '(' << t->key << ',' << t->info << ')';
				print(out, t->right);
				out << ']';
			}
			else out << "nullptr";
			out << endl;
		}

		static void deleteNode(TreeNode *t)
		// O(1)
		{
			delete t;
		}

		static void deleteTree(TreeNode *t)
		// O(lgN)
		{
			if (t)
			{
				deleteTree(t->left);
				deleteTree(t->right);
				deleteNode(t);
			}
		}
	};
	TreeNode *root;

public:
	BinarySearchTree()
		:root(nullptr) {}

	BinarySearchTree(const BinarySearchTree &bst)
	{
		root = TreeNode::copy(bst.root);
	}

	void length_count(int *l_c)
	{
		TreeNode::length_count(l_c, root);
	}

	void insert(KeyType key, ElementType info)
	// O(lgN)
	{
		root = TreeNode::insert(key, info, root);
	}

	ElementType find(KeyType key)
	// O(lgN)
	{
		TreeNode *t = TreeNode::find(key, root);
		if (!t)
		{
			insert(key, ElementType());
			t = TreeNode::find(key, root);
		}
		return t->info;
	}

	ElementType& operator [] (KeyType key)
	// O(lgN)
	{
		TreeNode *t = TreeNode::find(key, root);
		if (!t)
		{
			insert(key, ElementType());
			t = TreeNode::find(key, root);
		}
		return t->info;
	}

	void remove(KeyType key)
	// O(lgN)
	{
		root = TreeNode::remove(key, root);
	}

	void print(ostream &out)
	{
		TreeNode::print(out, root);
	}

	~BinarySearchTree()
	{
		TreeNode::deleteTree(root);
	}
};
