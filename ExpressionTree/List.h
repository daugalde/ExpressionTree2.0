#pragma once
#include "TreeNode.h"

using namespace std;

class List {

private:
	

public:
	TreePointerNode head;

	List() {
		head = NULL;
	}

	List(TreePointerNode head) {
		this->head = head;
	}
	~List() {
		this->head = NULL;
	};
	void Add(TreePointerNode value); // Insert at Beginning
	bool IsEmpty() { return head == NULL; }
	void Display();
	string DisplayLastElementInfo();
	TreePointerNode Remove();
	int Length();

	friend class Stack;

};