#include <iostream>
#include "BSTree.h"

using namespace std;

int main() {

	BSTree* bst = new BSTree();	
	bst->insert(5);
	bst->insert(3);
	bst->insert(7);
	bst->insert(6);
	bst->insert(30);
	bst->insert(1);
	bst->insert(10);

	int height = bst->height();
	std::cout << "BST: " << "Height is " << height << std::endl;

	int dataToSearch = 30;
	Node* found = bst->search(dataToSearch);
	std::cout << "BST: " << dataToSearch << " is " << ((found != NULL) ? "FOUND" : "NOT FOUND") << std::endl;

	dataToSearch = 15;
	found = bst->search(dataToSearch);
	std::cout << "BST: " << dataToSearch << " is " << ((found != NULL) ? "FOUND" : "NOT FOUND") << std::endl;

	delete bst;
	bst = NULL;
	return 0;
}