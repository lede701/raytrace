#pragma once
template<class T>
class AVLNode
{
public:
	T* data;

	AVLNode* left;
	AVLNode* right;

	AVLNode* root;
};

