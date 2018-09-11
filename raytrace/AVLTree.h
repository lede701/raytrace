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

