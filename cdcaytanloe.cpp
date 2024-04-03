#include"thuviencaytanloe.h"
void preOrder(Node* root)
{
	if (root != NULL)
	{
		cout << root->key << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}
NodePtr createNode(int x)
{
	NodePtr p = new Node();
	p->key = x;
	p->left = p->right = NULL;
	return p;
}
void splayToRoot(NodePtr &r, NodePtr node)
{
	while (node != NULL)
	{
		node = splay(r, node);
	}
}
NodePtr find(NodePtr r, int x)
{
	if (r == NULL || r->key == x)
		return r;
	if (r->key < x)
		return find(r->right, x);
	return find(r->left, x);
}
NodePtr findAndSplay(NodePtr r, int x) {
	
	NodePtr node = find(r, x);
	if (node != NULL) {
		splayToRoot(r, node);
	}
	return node;
}

void rotateRight(NodePtr &r)
{
	if (r == NULL || r->left == NULL) return;
	NodePtr p = r->left;
	r->left = p->right;
	p->right = r;
	r = p;
}
void rotateLeft(NodePtr &r)
{
	if (r == NULL || r->right == NULL) return;
	NodePtr p = r->right;
	r->right = p->left;
	p->left = r;
	r = p;
}
NodePtr splay(NodePtr &r, NodePtr nodeX)
{
	if (r == NULL) return NULL;
	if (r->left == nodeX)
	{
		//Zig: Quay phải 
		rotateRight(r);
		return r;
	}
	else if (r->right == nodeX)
	{
		//Zig: quay trái 
		rotateLeft(r);
		return r;
	}
	else
	{
		NodePtr p;
		if (nodeX->key < r->key)
		{
			p = r->left;
			if (p == NULL) return NULL;
			if (p->left == nodeX) //Zig-Zig:
			{
				rotateRight(r);
				rotateRight(r);
				return r;
			}
			else if (p->right == nodeX) //Zig-Zag:
			{
				rotateLeft(r->left);
				rotateRight(r);
				return r;
			}
			else {
				return splay(r->left, nodeX);
			}
		}
		else if (nodeX->key > r->key)
		{
			p = r->right;
			if (p == NULL) return NULL;
			if (p->right == nodeX) //Zig-Zig:
			{
				rotateLeft(r);
				rotateLeft(r);
				return r;
			}
			else if (p->left == nodeX) //Zig-Zag:
			{
				rotateRight(r->right);
				rotateLeft(r);
				return r;
			}
			else {
				return splay(r->right, nodeX);
			}
		}
		else return NULL;
	}
}
NodePtr insert(NodePtr&r, int x)
{
	if (r == NULL) {
		r = createNode(x);
		return r;
	}
	else if (x < r->key)
		return insert(r->left, x);
	else if (x > r->key)
		return insert(r->right, x);
}
NodePtr insertAndSplay(NodePtr &r, int x)
{
	NodePtr node = insert(r, x);
	splayToRoot(r, node);
	return node;
}
NodePtr deleteNodeAndSplay(NodePtr&r, int x)
{
	NodePtr p = find(r, x);
	if (p == NULL)
		return r;
	splayToRoot(r, p);
	p = r->left;
	while (p->right != NULL)
		p = p->right;
	splayToRoot(r->left, p);
	p = r;
	r = r->left;
	r->right = p->right;
	delete p;
	return r;
}
