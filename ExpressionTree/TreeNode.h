#pragma once
#include <iostream>
#include <string>
using namespace std;

class TreeNode {

private:
	string element;
	TreeNode* NextNode;
	TreeNode* Left;
	TreeNode* Right;
	int ExpressionResult;
	string operatorToApply;

public:  // Constructors

	TreeNode() {
		element = "";
		Left = NULL;
		Right = NULL;
		ExpressionResult = 0;
	}

	TreeNode(string element)
	{
		this->element = element;
		Left = NULL;
		Right = NULL;
		NextNode = NULL;
		ExpressionResult = 0;
	}

	TreeNode(string element, TreeNode* newNextNode)
	{
		this->element = element;
		NextNode = newNextNode;
	}

	void SetElement(string element) {
		this->element = element;
	}

	string GetElement() {
		return this->element;
	}

	void SetLeft(TreeNode* left) {
		this->Left = left;
	}

	TreeNode* GetLeft() {
		return Left;
	}

	void SetRight(TreeNode* right) {
		this->Right = right;
	}

	TreeNode* GetRight() {
		return Right;
	}

	void SetExpressionResult(int value) {
		this->ExpressionResult = value;
	}

	int GetExpressionResult() {
		return this->ExpressionResult;
	}

	void SetOperator(string operatorToApply) {
		this->operatorToApply = operatorToApply;
	}

	string GetOperator() {
		return this->operatorToApply;
	}

	friend class Stack;
	friend class List;
	friend class ExpressionProcessor;
};

typedef TreeNode* TreePointerNode; //Alias
