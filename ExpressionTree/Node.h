#pragma once
#include <iostream>
#include <string>
using namespace std;

class Node {

private:
	string element;
	Node* NextNode;
	Node* Left;
	Node* Right;

public:  // Constructors

	Node() {
		element = "";
		NextNode = NULL;
		Left = NULL;
		Right = NULL;
	}

	Node(string element)
	{
		this->element = element;
		NextNode = NULL;
	}

	Node(string element, Node* newNextNode)
	{
		this->element = element;
		NextNode = newNextNode;
	}

	void SetLeft(Node* left) {
		this->Left = left;
	}

	Node* GetLeft() {
		return Left;
	}

	void SetRight(Node* right) {
		this->Right = right;
	}

	Node* GetRight() {
		return Right;
	}

	friend class Stack;
	friend class StaticQueue;
	friend class List;
	friend class FileLoader;
	friend class ExpressionProcessor;
};

typedef Node* PointerNode; //Alias
