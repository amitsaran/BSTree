#include <iostream>
#include "Node.h"
using namespace std;

Node::Node(const int& data)
{
	this->_data = data;
	this->_left = NULL;
	this->_right = NULL;
}

Node::~Node()
{
	this->_data = 0;
	if (this->_left != NULL) {
		delete this->_left;
		this->_left = NULL;
	}
	if (this->_right) {
		delete this->_right;
		this->_right = NULL;
	}
}

int& Node::getData(){
	return this->_data;
}

Node* Node::getLeft() {
	return this->_left;
}

Node* Node::getRight() {
	return this->_right;
}

void Node::setData(const int& iData) {
	this->_data = iData;
}

void Node::setLeft(Node* iNode) {
	this->_left = iNode;
}

void Node::setRight(Node* iNode) {
	this->_right = iNode;
}

