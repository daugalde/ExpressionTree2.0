#include <iostream>
#include "Node.h"
#include <string>
#include "TreeNode.h"
#include <fstream> 
using namespace std;
#pragma once

class BinaryTree {

public:

	void InOrder(TreeNode*);

	void PreOrder(TreeNode*);

	void PostOrder(TreeNode*);

	int EvaluateExpression(TreeNode*, ofstream*);

	bool CheckIfNumber(string element);
};