#include <iostream>
#include "BSTree.h"

using namespace std;

int main() {

	BSTree* bst = new BSTree();	
	bst->insert(50);
	bst->insert(30);
	bst->insert(70);
	bst->insert(60);
	bst->insert(80);
	bst->insert(40);
	bst->insert(20);
	bst->insert(10);
	bst->insert(25);

	int height = bst->height();
	std::cout << "BST: " << "Height is " << height << std::endl;

	int dataToSearch = 30;
	Node* found = bst->search(dataToSearch);
	std::cout << "BST: " << dataToSearch << " is " << ((found != NULL) ? "FOUND" : "NOT FOUND") << std::endl;

	dataToSearch = 15;
	found = bst->search(dataToSearch);
	std::cout << "BST: " << dataToSearch << " is " << ((found != NULL) ? "FOUND" : "NOT FOUND") << std::endl;

	bst->print(false);

	delete bst;
	bst = NULL;
	return 0;
}