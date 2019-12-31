#include "AVLTree.h"

int main()
{
	AVLTree* avl = new AVLTree();
	avl->add(14);
	avl->showTree();
	avl->add(17);
	avl->showTree();
	avl->add(11);
	avl->showTree();
	avl->add(7);
	avl->showTree();
	avl->add(53);
	avl->showTree();
	avl->add(4);
	avl->showTree();
	avl->add(13);
	avl->showTree();
	avl->remove(14);
	avl->showTree();
	avl->showNum();
	

	return 0;
}