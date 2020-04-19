#include <iostream>
#include <string>
#include "BSTree.h"

using namespace std;
void _printVector(std::vector<Node*> list, std::string str);

int main() {
	int height = 0;
	BSTree* bst = new BSTree();
	height = bst->height();
	//
	//                       25
	//            ------------------------
	//            |                      |
	//           15                     50
	//       ------------           --------------
	//       |          |           |            |
	//       10         22          35           70
	//    --------   ---------    --------     --------
	//    |      |   |       |    |      |     |      |
	//    4     12   18     24    31    44     66     90
	//
	bst->add(25);
	bst->add(15);
	bst->add(50);
	bst->add(10);
	bst->add(22);
	bst->add(35);
	bst->add(70);
	bst->add(4);
	bst->add(12);
	bst->add(18);
	bst->add(24);
	bst->add(31);
	bst->add(44);
	bst->add(66);
	bst->add(90);

	height = bst->height();
	std::cout << "BST: " << "Height is " << height << std::endl;

	//int dataToSearch = 25;
	//Node* nodeFound = NULL;
	//Node* parentNode = NULL;
	//bst->find(dataToSearch, nodeFound, parentNode);
	//std::cout << "BST: " << dataToSearch << " is " << ((nodeFound != NULL) ? "FOUND. " : "NOT FOUND. ");
	//std::cout << "Parent data is: " << ((parentNode == NULL) ? "NULL. " : std::to_string(parentNode->getData())) << std::endl;

	//dataToSearch = 15;
	//nodeFound = NULL;
	//parentNode = NULL;
	//bst->find(dataToSearch, nodeFound, parentNode);
	//std::cout << "BST: " << dataToSearch << " is " << ((nodeFound != NULL) ? "FOUND. " : "NOT FOUND. ");
	//std::cout << "Parent data is: " << ((parentNode == NULL) ? "NULL. " : std::to_string(parentNode->getData())) << std::endl;

	BSTree::TraverseType traverseType = BSTree::TraverseType::BFS;
	std::vector<Node*> bfsOrderList = bst->traverse(traverseType);
	_printVector(bfsOrderList, "BFS: ");
	bfsOrderList.clear();

	Node* smallest = NULL;
	Node* parentOfSmallest = NULL;
	bst->findSmallest(smallest, parentOfSmallest);
	Node* largest = NULL;
	Node* parentOfLargest = NULL;
	bst->findLargest(largest, parentOfLargest);

	//bst->remove(66);
	//bfsOrderList = bst->traverse(traverseType);
	//_printVector(bfsOrderList, "BFS: ");
	//bfsOrderList.clear();

	//bst->remove(70);
	//bfsOrderList = bst->traverse(traverseType);
	//_printVector(bfsOrderList, "BFS: ");
	//bfsOrderList.clear();

	bst->remove(50);
	bfsOrderList = bst->traverse(traverseType);
	_printVector(bfsOrderList, "BFS: ");
	bfsOrderList.clear();

	/*traverseType = BSTree::TraverseType::DFSInOrder;
	std::vector<Node*> inOrderList = bst->traverse(traverseType);
	_printVector(inOrderList, "DFS InOrder: ");*/

	//traverseType = BSTree::TraverseType::DFSPreOrder;
	//std::vector<Node*> preOrderList = bst->traverse(traverseType);
	//_printVector(preOrderList, "DFS PreOrder: ");

	//traverseType = BSTree::TraverseType::DFSPostOrder;
	//std::vector<Node*> postOrderList = bst->traverse(traverseType);
	//_printVector(postOrderList, "DFS PostOrder: ");

	delete bst;
	bst = NULL;
	return 0;
}

void _printVector(std::vector<Node*> list, std::string str) {
	std::cout << str;
	for (int i = 0; i < (int)(list.size()); i++) {
		std::cout << list[i]->getData() << ", ";
	}
	std::cout << std::endl;
}
