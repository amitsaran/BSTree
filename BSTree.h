#pragma once
#ifndef BSTREE_H
#define BSTREE_H

#include <vector>
#include "Node.h"

class BSTree
{
private:
	Node* _root;
	void _insert(const int& data, Node*& node);
	void _insert(Node*& nodeToBeInstrted, Node*& atNode);
	Node* _search(const int& data, Node* node);
	int _height(Node* node);
	std::string _printHorizontal(Node* node);
	std::string _printVertical(Node* node);
	std::string _printVertical(Node* node, int& height);
	std::vector<std::string> _printV(Node* node, int& width);
	std::string _getStrWithWidth(const std::string str, const int width);
public:
	BSTree();
	~BSTree();
	Node* getRoot();
	void setRoot(Node*& root);

	void insert(const int& data);
	Node* search(const int& data);
	int height();
	void print(const bool isHorizontal = true);	
};

#endif	//	!BSTREE_H

