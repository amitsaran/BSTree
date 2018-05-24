#include <iostream>
#include <string>
#include "BSTree.h"

using namespace std;

#define SPACE_WIDTH 5
#define NUMBER_WIDTH 2

BSTree::BSTree()
{
	this->_root = NULL;
}


BSTree::~BSTree()
{
	delete this->_root;
	this->_root = NULL;
}

Node* BSTree::getRoot() {
	return this->_root;
}

void BSTree::setRoot(Node*& root) {
	this->_root = root;
}

void BSTree::insert(const int& data) {
	Node* root = this->getRoot();
	if (root == NULL) {
		Node* n = new Node(data);
		this->setRoot(n);
	}
	else {
		this->_insert(data, root);
	}
}

Node* BSTree::search(const int& data) {
	return this->_search(data, this->getRoot());
}

int BSTree::height() {
	return this->_height(this->getRoot()) - 1;
}

void BSTree::_insert(const int& data, Node*& node) {
	Node* n = new Node(data);
	this->_insert(n, node);	
}

void BSTree::print(const bool isHorizontal) {
	std::string retStr = "";
	Node* root = this->getRoot();
	if(root != NULL){
		if (isHorizontal == true) {
			retStr = this->_printHorizontal(root);
		}
		else {
			retStr = this->_printVertical(root);
		}
	}
	std::cout << retStr << std::endl;
}

void BSTree::_insert(Node*& nodeToBeInstrted, Node*& atNode) {
	if ((nodeToBeInstrted != NULL) && (atNode != NULL)) {
		if (atNode->getData() > nodeToBeInstrted->getData()) {
			Node* left = atNode->getLeft();
			if (left != NULL) {
				this->_insert(nodeToBeInstrted, left);
			}
			else {
				atNode->setLeft(nodeToBeInstrted);
			}
		}
		else {
			Node* right = atNode->getRight();
			if (right != NULL) {
				this->_insert(nodeToBeInstrted, right);
			}
			else {
				atNode->setRight(nodeToBeInstrted);
			}
		}
	}
}

Node* BSTree::_search(const int& data, Node* node) {
	Node* _found = NULL;
	if (node != NULL) {
		int _data = node->getData();
		if (_data == data) {
			_found = node;
		}
		else if (_data > data) {
			_found = this->_search(data, node->getLeft());
		}
		else {
			_found = this->_search(data, node->getRight());
		}
	}
	return _found;
}

int BSTree::_height(Node* node) {
	int height = 0;
	if (node != NULL) {
		height = 1;

		int l = 0, r = 0;
		Node* lNode = node->getLeft();
		Node* rNode = node->getRight();
		if (lNode != NULL) {
			l = this->_height(lNode);
		}
		if (rNode != NULL) {
			r = this->_height(rNode);
		}

		height = height + ((l > r) ? l : r);
	}
	return height;
}

struct Trunk
{
	Trunk *prev;
	string str;

	Trunk(Trunk *prev, string str)
	{
		this->prev = prev;
		this->str = str;
	}
};

// Helper function to print branches of the binary tree
void showTrunks(Trunk *p)
{
	if (p == NULL)
		return;

	showTrunks(p->prev);

	std::cout << p->str;
}

void printTree(Node *root, Trunk *prev, bool isLeft)
{
	if (root == NULL)
		return;

	string prev_str = "	";
	Trunk *trunk = new Trunk(prev, prev_str);

	printTree(root->getLeft(), trunk, true);

	if (!prev)
		trunk->str = "---";
	else if (isLeft)
	{
		trunk->str = ".---";
		prev_str = "   |";
	}
	else
	{
		trunk->str = "`---";
		prev->str = prev_str;
	}

	showTrunks(trunk);
	cout << root->getData() << endl;

	if (prev)
		prev->str = prev_str;
	trunk->str = "   |";

	printTree(root->getRight(), trunk, false);
}

std::string BSTree::_printHorizontal(Node* node) {
	std::string retStr = "";
	printTree(node, NULL, false);
	return retStr;
}

std::string BSTree::_printVertical(Node* node) {
	int _width = 0;
	return this->_printVertical(node, _width);
}

std::string BSTree::_printVertical(Node* node, int& width) {
	std::string retStr = "";
	std::vector<std::string> listStr = this->_printV(node, width);
	int size = listStr.size();
	for (int i = 0; i < size; i++) {
		retStr = retStr + listStr[i] + "\n";
	}	
	return retStr;
}

std::vector<std::string> BSTree::_printV(Node* node, int& width) {
	std::vector<std::string> listStr;
	if (node) {
		Node* left = node->getLeft();
		Node* right = node->getRight();

		std::vector<std::string> listStrLeft, listStrRight;
		int leftWidth = 0, rightWidth = 0, maxChildrenWidth = 0;
		std::string nodeStr = "";
		if (left == NULL && right == NULL) {
			width = NUMBER_WIDTH;
			listStr.push_back(std::to_string(node->getData()));
		}
		else {

			listStrLeft = this->_printV(left, leftWidth);
			listStrRight = this->_printV(right, rightWidth);
			maxChildrenWidth = (leftWidth > rightWidth) ? leftWidth : rightWidth;
			width = 2* maxChildrenWidth + SPACE_WIDTH;
			int width_space = maxChildrenWidth + SPACE_WIDTH;
			std::string newLineStr = "\n", verticalLineStr = "|", horizontalLineStr = "-", plusStr = "+",
				spaceStr = " ";
			int halfWidth = width_space / 2;

			listStr.push_back(this->_getStrWithWidth(spaceStr, maxChildrenWidth/2) + this->_getStrWithWidth(spaceStr, halfWidth) + std::to_string(node->getData()));
			listStr.push_back(this->_getStrWithWidth(spaceStr, maxChildrenWidth/2) + this->_getStrWithWidth(spaceStr, halfWidth) + verticalLineStr);
			listStr.push_back(this->_getStrWithWidth(spaceStr, maxChildrenWidth/2) + this->_getStrWithWidth(horizontalLineStr, width_space));
			listStr.push_back(this->_getStrWithWidth(spaceStr, maxChildrenWidth/2) + verticalLineStr + 
				              this->_getStrWithWidth(spaceStr, (width_space - NUMBER_WIDTH)) + verticalLineStr);

			int sizeLeft = listStrLeft.size(), 
				sizeRight = listStrRight.size();
			int sizeMax = (sizeLeft > sizeRight) ? sizeLeft : sizeRight,
				sizeMin = (sizeLeft > sizeRight) ? sizeRight : sizeLeft;
			
			for (int i = 0; i < sizeMax; i++) {
				std::string tempLeftStr = (i < sizeLeft) ? listStrLeft[i] : " ";
				std::string tempRightStr = (i < sizeRight) ? listStrRight[i] : " ";
				listStr.push_back(tempLeftStr + this->_getStrWithWidth(spaceStr, SPACE_WIDTH) + tempRightStr);
			}			
		}	
	}
	else {
		width = 0;
	}
	return listStr;
}

std::string BSTree::_getStrWithWidth(const std::string str, const int width) {
	std::string retStr = "";
	for (int i = 0; i < width; i++) {
		retStr = retStr + str;
	}
	return retStr;
}


