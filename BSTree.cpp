#include <iostream>
#include "BSTree.h"

using namespace std;

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
	if (node->getData() > data) {
		Node* left = node->getLeft();
		if (left != NULL) {
			this->_insert(data, left);
		}
		else {
			Node* n = new Node(data);
			node->setLeft(n);
		}
	}
	else {
		Node* right = node->getRight();
		if (right != NULL) {
			this->_insert(data, right);
		}
		else {
			Node* n = new Node(data);
			node->setRight(n);
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

