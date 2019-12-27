#include "AVLTree.h"

int main()
{
	AVLTree* avl = new AVLTree();
	avl->add(4);
	avl->add(8);
	avl->add(6);
	//avl->add(1);
	//avl->add(9);
	//avl->add(10);

	avl->showTree();

	return 0;
}