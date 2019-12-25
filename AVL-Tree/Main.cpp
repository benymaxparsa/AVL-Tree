#include "AVLTree.h"

int main()
{
	AVLTree* avl = new AVLTree();
	avl->add(3);
	avl->add(5);
	avl->add(0);
	avl->add(1);
	avl->add(9);

	return 0;
}