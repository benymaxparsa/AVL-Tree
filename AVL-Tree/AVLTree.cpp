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

void AVLTree::add(Node* parent,Node* newNode)
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
		if (getHeight(node->left->left) > getHeight(node->left->right))
			node = rightRotate(node);
		else
			node = leftRightRotate(node);
	}
	else
	{
		if (getHeight(node->right->right) > getHeight(node->right->left))
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
	else
	{
		int lDepth = getHeight(node->left);
		int rDepth = getHeight(node->right);

		if (lDepth > rDepth)
			return(lDepth + 1);
		else return(rDepth + 1);
	}
}

Node* AVLTree::rightRotate(Node* node)
{
	Node* temp = node->left;
	node->left = temp->right;
	temp->right = node;
	temp->parent = node->parent;
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
	temp->parent = node->parent;
	node->parent = temp;
	return temp;
}

Node* AVLTree::rightLeftRotate(Node* node)
{
	node->right = rightRotate(node->right);
	return leftRotate(node);
}

void AVLTree::showTree()
{
	printBT(root);
}

void AVLTree::showNum()
{
	print(root);
}

void AVLTree::print(Node* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";
	print(root->left);
	print(root->right);
	return;
}

void AVLTree::printBT(Node* node)
{
	printBT("", node, false);
}

void AVLTree::printBT(const string& prefix, Node* node, bool isLeft)
{
	if (node)
	{
		cout << prefix;
		cout << (isLeft ? "├──" : "└──");
		cout << node->data << endl;

		printBT(prefix + (isLeft ? "│   " : "    "), node->left, true);
		printBT(prefix + (isLeft ? "│   " : "    "), node->right, false);
	}
}

