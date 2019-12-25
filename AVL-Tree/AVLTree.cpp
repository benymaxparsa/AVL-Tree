#include "AVLTree.h"

AVLTree::AVLTree()
{
	root = NULL;
	currentSize = 0;
}

AVLTree::~AVLTree()
{
}

void AVLTree::add(int data)
{
	Node* node = new Node(data);
	if (!root)
	{
		root = node;
		currentSize++;
		return;
	}
	add(root, node);
}

void AVLTree::add(Node* parent, Node* newNode)
{
	if (newNode->data > parent->data)
	{
		if (!parent->right)
		{
			parent->right = newNode;
			newNode->parent = parent;
			currentSize++;
		}
		else
			add(parent->right, newNode);
	}
	else
	{
		if(!parent->left)
		{
			parent->left = newNode;
			newNode->parent = parent;
			currentSize++;
		}
		else
			add(parent->left, newNode);
	}
	checkBalance(newNode);
}

void AVLTree::checkBalance(Node* node)
{
}

void AVLTree::reBalance(Node* node)
{
}
