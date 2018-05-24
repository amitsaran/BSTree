#pragma once
#ifndef BSTREE_H
#define BSTREE_H

#include "Node.h"

class BSTree
{
private:
	Node* _root;
	void _insert(const int& data, Node*& node);
	Node* _search(const int& data, Node* node);
	int _height(Node* node);
public:
	BSTree();
	~BSTree();
	Node* getRoot();
	void setRoot(Node*& root);

	void insert(const int& data);
	Node* search(const int& data);
	int height();
};

#endif	//	!BSTREE_H

