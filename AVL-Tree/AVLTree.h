#ifndef AVLTree_h
#define AVLTree_h

#include"Node.h"
#include <algorithm>

class AVLTree
{
public:
	AVLTree();
	~AVLTree();
	void add(int data);
	void showTree();
	void showNum();
	void remove(int x);
	void min();

private:
	Node* root;
	int currentSize;
	void add(Node* parent,Node* newNode);
	void checkBalance(Node* node);
	void reBalance(Node* node);
	int getHeight(Node* node);
	Node* rightRotate(Node* node);
	Node* leftRightRotate(Node* node);
	Node* leftRotate(Node* node);
	Node* rightLeftRotate(Node* node);
	void printBT(Node* node);
	void printBT(const string& prefix, Node* node, bool isLeft);
	void print(Node* root);
	int Diff(Node* root);
	Node* remove(int x, Node* t);
	Node* findMin(Node* t);
	Node* findMax(Node* t);
};


#endif // !AVLTree_h
