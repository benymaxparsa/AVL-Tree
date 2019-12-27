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
	if ((getHeight(node->left) - getHeight(node->right) > 1) || (getHeight(node->left) - getHeight(node->right) < -1))
	{
		reBalance(node);
	}
	if (!node->parent)
		return;
	checkBalance(node->parent);
}

void AVLTree::reBalance(Node* node)
{
	if (getHeight(node->left) - getHeight(node->right) > 1)
	{
		if (getHeight(node->left) > getHeight(node->right))
			node = rightRotate(node);
		else
			node = leftRightRotate(node);
	}
	else
	{
		if (getHeight(node->right) > getHeight(node->left))
			node = leftRotate(node);
		else
			node = rightLeftRotate(node);
	}
	if (!node->parent)
		root = node;
}

int AVLTree::getHeight(Node* node)
{
	if (node == NULL)
		return 0;
	int leftH = getHeight(node->left);
	int rightH = getHeight(node->right);

	return 1 + max(leftH, rightH);
}

Node* AVLTree::rightRotate(Node* node)
{
	Node* temp = node->left;
	node->left = temp->right;
	temp->right = node;
	return temp;
}

Node* AVLTree::leftRightRotate(Node* node)
{
	node->left = leftRotate(node->left);
	return rightRotate(node);
}

Node* AVLTree::leftRotate(Node* node)
{
	Node* temp = node->right;
	node->right = temp->left;
	temp->left = node;
	return temp;
}

Node* AVLTree::rightLeftRotate(Node* node)
{
	node->right = rightRotate(node->right);
	return leftRotate(node);
}
