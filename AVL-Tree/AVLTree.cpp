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

Node* AVLTree::findMin(Node* t)
{
	if (t == NULL)
		return NULL;
	else if (t->left == NULL)
		return t;
	else
		return findMin(t->left);
}

Node* AVLTree::findMax(Node* t)
{
		if (t == NULL)
			return NULL;
		else if (t->right == NULL)
			return t;
		else
			return findMax(t->right);
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

Node* AVLTree::remove(int x, Node* t)
{
	Node* temp;
	if (t == NULL)
		return NULL;
	else if (x < t->data)
		t->left = remove(x, t->left);
	else if (x > t->data)
		t->right = remove(x, t->right);
	else if (t->left && t->right)
	{
		temp = findMin(t->right);
		t->data = temp->data;
		t->right = remove(t->data, t->right);
	}
	else
	{
		temp = t;
		if (t->left == NULL)
			t = t->right;
		else if (t->right == NULL)
			t = t->left;
		delete temp;
	}

	return t;
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
	int balanceFactor = Diff(node);

	if (balanceFactor > 1) {
		if (Diff(node->left) > 0) {
			node = rightRotate(node);
		}
		else {
			node = leftRightRotate(node);
		}
	}
	else if (balanceFactor < -1) {
		if (Diff(node->right) > 0) {
			node = rightLeftRotate(node);
		}
		else {
			node = leftRotate(node);
		}
	}

}

int AVLTree::getHeight(Node* node)
{
	if (!node) {
		return 0;
	}
	if (!node->left && !node->right) {
		return 1;
	}
	else {
		int l = getHeight(node->left);
		int r = getHeight(node->right);
		return (1 + ((l > r) ? l : r));
	}
}

int AVLTree::Diff(Node* temp) {
	int l_GetHeight = getHeight(temp->left);
	int r_GetHeight = getHeight(temp->right);
	int b_factor = (l_GetHeight - r_GetHeight);
	return b_factor;
}

Node* AVLTree::rightRotate(Node* node)
{
	Node* temp = node->left;
	node->left = temp->right;
	temp->right = node;
	temp->parent = node->parent;
	node->parent = temp;
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

void AVLTree::remove(int x)
{
	root = remove(x, root);
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

