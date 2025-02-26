/*
* file			listmanipulator.cpp
* description 	binary search trees kullanarak ağaçlar arasında gezinme ve ağaçların üstünde işlem yapma
* course		veri yapıları 1. öğretim B grubu
* assignment 	2. ödev
* date 			25.12.2024
* author		Sude ANDURMAN , sude.andurman@ogr.sakarya.edu.tr
*/

#include "listmanipulator.hpp"

ListManipulator :: ListManipulator()
{
	head = nullptr;
}

ListManipulator :: ~ListManipulator()
{
	Node*	current;
	Node*	nextNode;

	current = head;
	while (current != nullptr)
	{
		nextNode = current->next;
		delete current->top;
		delete current;
		current = nextNode;
	}
}

void	ListManipulator :: addToLastIndex (BSTNode* root)
{
	if (root == nullptr)
		return;
	Node*	newNode = new Node(root);
	if (head == nullptr)
		head = newNode;
	else
	{
		Node*	current = head;
		while (current->next != nullptr)
			current = current->next;
		current->next = newNode;
	}
}

BSTNode*	ListManipulator :: InsertTree(BSTNode* root, char data)
{
	if (root == nullptr)
	{
		root = new BSTNode(data);
	}
	else if (data < root->data)
	{
		root->left = InsertTree(root->left, data);
	}
	else if (data > root->data)
	{
		root->right = InsertTree(root->right, data);
	}
	return (root);
}

int		ListManipulator :: getDatasFromFile(const string& filename, BSTNode* root)
{
	ifstream file(filename);
	if (!file.is_open())
		throw "Dosya açilamadi";

	int		count;
	int		idx;
	string	tree;

	count = 0;
	while (getline(file, tree))
	{
		idx = 0;
		while (tree[idx])
		{
			root = InsertTree(root, tree[idx]);
			idx++;
		}
		addToLastIndex(root);
		count++;
		root = nullptr;
	}
	file.close();
	return (count);
}

int		ListManipulator :: CalculateTreeValue(BSTNode* node, int start)
{
	if (node == nullptr)
		return 0;
	
	int	total;

	if (start == 0)
		total = node->data;  
	else
		total = 0;

	if (node->left != nullptr)
	{
		total += 2 * (node->left->data);
		if (node->left->left != nullptr || node->left->right != nullptr)
			total += CalculateTreeValue(node->left, start + 1);
	}
	if (node->right != nullptr)
	{
		total += node->right->data;
		if (node->right->left != nullptr || node->right->right != nullptr)
			total += CalculateTreeValue(node->right, start + 1);
	}
	return (total);
}

void	ListManipulator :: DisplayMenu (size_t node_idx)
{
	Node*	current;
	Node*	start_node;
	int	page;
	int start_idx;
	int counter;

	current = head;
	page = node_idx / 5;
	counter = -1;
	if (page > 0)
	{
		start_idx = page * 5;
		while (++counter < start_idx && current->next != nullptr)
			current = current->next;
	}
	counter = node_idx % 5;
	DisplayNodeAddress(current);
	DisplayTreeValue(current);
	DisplayNodeAddress(current->next);
	DisplayPointer(counter);
}

void ListManipulator :: DisplayNodeAddress(Node* current)
{
	int		counter;
	Node*	start_node;

	counter = 0;
	start_node = current;
	while (counter < 5 && current)
	{
		cout << "........  ";
		counter++;
		current = current->next;
	}
	cout << endl;
	current = start_node;
	counter = 0;

	while (counter < 5 && current)
	{
		uintptr_t addr = reinterpret_cast<uintptr_t>(current);
		cout << ":" <<addr % 10000 << "  :  ";
		counter++;
		current = current->next;
	}
	cout << endl;
	current = start_node;
	counter = 0;

	while (counter < 5 && current)
	{
		cout << "........  ";
		counter++;
		current = current->next;
	}
	cout << endl;
	current = start_node;
}

void ListManipulator :: DisplayTreeValue(Node* current)
{
	int		counter;
	Node*	start_node;

	counter = 0;
	start_node = current;
	while (counter < 5 && current)
	{
		cout << "........  ";
		counter++;
		current = current->next;
	}
	cout << endl;
	current = start_node;
	counter = 0;

	while (counter < 5 && current)
	{
		cout << ":" <<CalculateTreeValue(current->top, 0) << "  :  ";
		counter++;
		current = current->next;
	}
	cout << endl;
	current = start_node;
	counter = 0;

	while (counter < 5 && current)
	{
		cout << "........  ";
		counter++;
		current = current->next;
	}
	cout << endl;
	current = start_node;
}

void ListManipulator :: DisplayPointer(int idx)
{
	int	current;

	current = idx;
	while (--current >= 0)
	{
		cout << "          ";
	}
	cout << "^^^^^^^" << endl;
	current = idx;
	while (--current >= 0)
	{
		cout << "          ";
	}
	cout << "|||||||" <<endl;
}

void ListManipulator :: FindTreeToReverse(size_t node_idx)
{
	BSTNode*	root;
	Node*		current ;
	size_t		counter;

	current = head;
	counter = 0;
	while (current != nullptr && counter < node_idx)
	{
		current = current->next;
		counter++;
	}
	root = current->top;
	ReverseTree(root);
}

void ListManipulator :: ReverseTree(BSTNode* node)
{
	BSTNode*	temp;

	if (node == nullptr)
		return;

	temp = node->left;
	node->left = node->right;
	node->right = temp;

	ReverseTree(node->left);
	ReverseTree(node->right);
}

void ListManipulator :: DeleteTree(size_t node_idx)
{
	Node*	current;
	Node*	previous;
	size_t	counter;

	current = head;
	previous = nullptr;
	counter = 0;
	while (current != nullptr && counter < node_idx)
	{
		previous = current;
		current = current->next;
		counter++;
	}
	if (node_idx == 0)
		head = current->next;
	else
		previous->next = current->next;
	delete current;
}
