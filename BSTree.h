#pragma once
#ifndef BSTREE_H
#define BSTREE_H

#include <vector>
#include "Node.h"

class BSTree
{
public:
	BSTree();
	~BSTree();

	// DFS: Depth First Search
	//		DFSInOrder: LNR(Left-Node-Right)
	//		DFSPreOrder: NLR(Node-Left-Right)
	//		DFSPostOrder: LRN(Left-Right-Node)
	// BFS: Breadth First Search
	enum  TraverseType { DFSInOrder = 0, DFSPreOrder = 1, DFSPostOrder = 2, BFS = 3 };
			
	void  add(const int data);
	void  remove(const int data);	
	void  find(const int data, Node*& location, Node*& parent);
	void  findSmallest(Node*& location, Node*& parent);
	void  findLargest(Node*& location, Node*& parent);
	int   height();
	std::vector<Node*> traverse(const TraverseType traverseType = TraverseType::DFSInOrder);
	Node* root();

private:
	Node* _root;
	void  _setRoot(Node* root);
	void  _add(Node*& nodeToBeInstrted, Node*& atNode);
	void  _remove(Node*& location, Node*& parent);
	void  _find(const int data, Node* startNode, Node* startParentNode, Node*& location, Node*& parent);
	void  _findSmallest(Node* startNode, Node* startParentNode, Node*& location, Node*& parent);
	void  _findLargest(Node* startNode, Node* startParentNode, Node*& location, Node*& parent);
	int   _height(Node* node);
	void  _traverse_DFSInOrder(Node* node, std::vector<Node*>& nodesList);
	void  _traverse_DFSPreOrder(Node* node, std::vector<Node*>& nodesList);
	void  _traverse_DFSPostOrder(Node* node, std::vector<Node*>& nodesList);
	void  _traverse_BFS(Node* node, std::vector<Node*>& nodesList);
};

#endif	//	!BSTREE_H

