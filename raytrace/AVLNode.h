#pragma once
template<class T>
struct AVLNode
{
public:
	T data;

	AVLNode* left;
	AVLNode* right;

	AVLNode* root;
};

