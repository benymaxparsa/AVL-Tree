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

private:
	Node* root;
	int currentSize;
	void add(Node* parent, Node* newNode);
	void checkBalance(Node* node);
	void reBalance(Node* node);
	int getHeight(Node* node);
	Node* rightRotate(Node* node);
	Node* leftRightRotate(Node* node);
	Node* leftRotate(Node* node);
	Node* rightLeftRotate(Node* node);
};


#endif // !AVLTree_h
