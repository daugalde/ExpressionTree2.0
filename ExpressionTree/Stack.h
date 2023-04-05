#pragma once
#include <iostream>
#include <string>
#include "TreeNode.h"
#include "List.h"

using namespace std;

class Stack : public List {

public:

	Stack() {}
	~Stack() {
		this->head = NULL;
	};
	int Length();
	bool IsEmpty() { return head == NULL; }
	void Push(TreePointerNode value);
	TreePointerNode Pop();
	void Display();
	string Peek();

	friend class ExpressionProcessor;
};