#pragma once
#ifndef NODE_H
#define NODE_H

class Node
{
private:
	int _data;
	Node* _left;
	Node* _right;
public:
	Node(const int& data);
	~Node();

	int& getData();
	Node* getLeft();
	Node* getRight();

	void setData(const int& iData);
	void setLeft(Node* iNode);
	void setRight(Node* iNode);
};

#endif // !NODE_H

