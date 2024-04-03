#pragma once
#include <iostream> 
using namespace std;
struct Node
{
	int key;
	Node* left;
	Node* right;
};
typedef Node* NodePtr;
NodePtr createNode(int x);
void rotateRight(NodePtr &r);
void rotateLeft(NodePtr &r);
NodePtr splay(NodePtr &r, NodePtr nodeX);
NodePtr find(NodePtr r, int x);
NodePtr findAndSplay(NodePtr r, int x);
NodePtr insert(NodePtr&r, int x);
NodePtr insertAndSplay(NodePtr &r, int x);
NodePtr deleteNodeAndSplay(NodePtr&r, int x);
void splayToRoot(NodePtr &r, NodePtr node);
void preOrder(Node* root);
