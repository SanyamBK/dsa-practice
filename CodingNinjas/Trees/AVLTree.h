#include <bits/stdc++.h>
using namespace std;

class AVLTree
{
	struct Node
	{
		int data;
		Node *left;
		Node *right;
		int height;
		Node(int data)
		{
			this->data = data;
			this->height = 1;
			this->left = NULL;
			this->right = NULL;
		}
	};

private:
	Node *root = NULL;

	int height(Node *node)
	{
		if (node == NULL)
		{
			return 0;
		}
		return node->height;
	}

	int balanceFactor(Node *n)
	{
		if (n == NULL)
		{
			return 0;
		}
		return height(n->left) - height(n->right);
	}

	Node *leftRotation(Node *x)
	{
		Node *y = x->right;
		Node *t2 = y->left;

		x->right = t2;
		y->left = x;

		x->height = 1 + max(height(x->left), height(x->right));
		y->height = 1 + max(height(y->left), height(y->right));
		return y;
	}

	Node *rightRotation(Node *y)
	{
		Node *x = y->left;
		Node *t2 = x->right;

		y->left = t2;
		x->right = y;

		y->height = 1 + max(height(y->left), height(y->right));
		x->height = 1 + max(height(x->left), height(x->right));
		return x;
	}

	Node *insertRecursive(Node *node, int num)
	{
		if (node == NULL)
		{
			return new Node(num);
		}

		if (node->data <= num)
		{
			node->right = insertRecursive(node->right, num);
		}
		else if (node->data > num)
		{
			node->left = insertRecursive(node->left, num);
		}

		// update the height
		node->height = 1 + max(height(node->left), height(node->right));
		int balFactor = balanceFactor(node);
		if (balFactor > 1)
		{
			// right rotation
			if (num < node->left->data)
			{
				return rightRotation(node);
			}
			else
			{
				node->left = leftRotation(node->left);
				return rightRotation(node);
			}
		}
		if (balFactor < -1)
		{
			// left rotation
			if (num > node->right->data)
			{
				return leftRotation(node);
			}
			else
			{
				node->right = rightRotation(node->right);
				return leftRotation(node);
			}
		}
		return node;
	}

	Node *deleteRecursive(Node *curr, int val)
	{
		if (curr == NULL)
		{
			return NULL;
		}

		if (curr->data == val)
		{
			if (curr->left == NULL && curr->right == NULL)
			{
				delete curr;
				return NULL;
			}
			else if (curr->left == NULL)
			{
				Node *temp = curr->right;
				delete curr;
				return temp;
			}
			else if (curr->right == NULL)
			{
				Node *temp = curr->left;
				delete curr;
				return temp;
			}
			else
			{
				Node *temp = curr->right;
				while (temp->left != NULL)
				{
					temp = temp->left;
				}
				curr->data = temp->data;
				curr->right = deleteRecursive(curr->right, temp->data);
			}
		}
		else if (curr->data > val)
		{
			curr->left = deleteRecursive(curr->left, val);
		}
		else
		{
			curr->right = deleteRecursive(curr->right, val);
		}

		// update the height
		curr->height = 1 + max(height(curr->left), height(curr->right));
		int balFactor = balanceFactor(curr);
		if (balFactor > 1)
		{
			// right rotation
			if (balanceFactor(curr->left) >= 0)
			{
				return rightRotation(curr);
			}
			else
			{
				curr->left = leftRotation(curr->left);
				return rightRotation(curr);
			}
		}
		if (balFactor < -1)
		{
			// left rotation
			if (balanceFactor(curr->right) <= 0)
			{
				return leftRotation(curr);
			}
			else
			{
				curr->right = rightRotation(curr->right);
				return leftRotation(curr);
			}
		}
		return curr;
	}

	bool help_search(Node *curr, int val)
	{
		if (curr == NULL)
		{
			return false;
		}

		if (curr->data == val)
		{
			return true;
		}
		else if (curr->data > val)
		{
			return help_search(curr->left, val);
		}
		else
		{
			return help_search(curr->right, val);
		}
	}

public:
	AVLTree()
	{
		root = NULL;
	}

	void insertNode(int num)
	{
		root = insertRecursive(root, num);
	}

	void deleteNode(int num)
	{
		root = deleteRecursive(root, num);
	}

	bool search(int val)
	{
		return help_search(root, val);
	}

	void print()
	{
		queue<Node *> q;
		q.push(root);
		while (!q.empty())
		{
			Node *n = q.front();
			q.pop();
			Node *l = n->left;
			Node *r = n->right;
			int lnum = -1;
			int rnum = -1;
			if (l != NULL)
			{
				lnum = l->data;
				q.push(l);
			}
			if (r != NULL)
			{
				rnum = r->data;
				q.push(r);
			}
			cout << "Node " << n->data << " leftChild: " << lnum << "  rightChild: " << rnum << endl;
		}
	}
};

