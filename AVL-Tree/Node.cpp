#include "Node.h"


Node::Node(int data)
{
	this->data = data;
	left = NULL;
	right = NULL;
	parent = NULL;
}

Node::~Node()
{
}
