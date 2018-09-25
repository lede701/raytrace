#pragma once
#include <stdlib.h>
#include "AVLNode.h"

template<class T>
class AVLTree
{
public:
	AVLNode<T> *root;

	AVLTree();
	~AVLTree();

	int Height();
	int Height(AVLNode<T>* node);

	int diff(AVLNode<T>* node);

	AVLNode<T>* rrRoation(AVLNode<T>* node);
	AVLNode<T>* llRoation(AVLNode<T>* node);
	AVLNode<T>* rlRoation(AVLNode<T>* node);
	AVLNode<T>* lrRoation(AVLNode<T>* node);

	AVLNode<T>* balance(AVLNode<T>* node);
	AVLNode<T>* insert(T idx, AVLNode<T>* node=NULL);
};

template<class T>
AVLTree<T>::AVLTree()
{
	root = NULL;
}

template<class T>
AVLTree<T>::~AVLTree()
{
}

template<class T>
int AVLTree<T>::Height()
{
	return Height(root);
}

template<class T>
int AVLTree<T>::Height(AVLNode<T>* node)
{
	int h = 0;

	if (node != NULL)
	{
		int l_height = Height(node->left);
		int r_height = Height(node->right);
		int max = max(l_height, r_height);
		h = max + 1;
	}

	return h;
}

template<class T>
int AVLTree<T>::diff(AVLNode<T>* node)
{
	int l_height = Height(node->left);
	int r_height = Height(node->right);
	int factor = l_height - r_height;
	return factor;
}

template<class T>
AVLNode<T>* AVLTree<T>::rrRoation(AVLNode<T>* node)
{
	AVLNode<T>* temp;
	temp = node->right;
	node->right = temp->left;
	temp->left = node;
	return temp;
}

template<class T>
AVLNode<T>* AVLTree<T>::llRoation(AVLNode<T>* node)
{
	AVLNode<T>* temp;
	temp = node->left;
	node->left = temp->right;
	temp->right = node;
	return temp;
}

template<class T>
AVLNode<T>* AVLTree<T>::lrRoation(AVLNode<T>* node)
{
	AVLNode<T>* temp;
	temp = node->left;
	node->left = rrRoation(temp);
	return llRoation(node);
}

template<class T>
AVLNode<T>* AVLTree<T>::rlRoation(AVLNode<T>* node)
{
	AVLNode<T>* temp;
	temp = node->right;
	node->left = llRoation(temp);
	return rrRoation(node);
}

template<class T>
AVLNode<T>* AVLTree<T>::balance(AVLNode<T>* node)
{
	int balFactor = diff(node);
	if (balFactor > 1)
	{
		if (diff(node->left) > 0)
		{
			node = llRoation(node);
		}
		else
		{
			node = lrRoation(node);
		}
	}
	else if (balFactor < -1)
	{
		if (diff(node->right) > 0)
		{
			node = rlRoation(node);
		}
		else
		{
			node = rrRoation(node);
		}
	}

	return node;
}

template<class T>
AVLNode<T>* AVLTree<T>::insert(T value, AVLNode<T>* node)
{
	if (node == NULL)
	{
		if (root == NULL)
		{
			root = new AVLNode<T>();
			root->data = value;
			root->left = NULL;
			root->right = NULL;
			root->root = NULL;

			return root;
		}
		else
		{
			if (node == NULL)
			{
				node = new AVLNode<T>();
				node->data = value;
				node->root = root;
				node->left = NULL;
				node->right = NULL;
			}
			else if (value < root->data)
			{
				node->left = insert(value, node->left);
				node = balance(node);

			}
			else if (value >= root->data)
			{
				node->right = insert(value, node->right);
				node = balance(node);
			}
		}
	}

	return node;
}