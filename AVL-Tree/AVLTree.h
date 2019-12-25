#ifndef AVLTree_h
#define AVLTree_h

#include"Node.h"

class AVLTree
{
public:
	AVLTree();
	~AVLTree();
	void add(int data);
	void add(Node* parent, Node* newNode);
	void checkBalance(Node* node);
	void reBalance(Node* node);

private:
	Node* root;
	int currentSize;
};


#endif // !AVLTree_h
