#pragma once
#include "StaticQueue.h"
#include "Stack.h"
using namespace std;

class ExpressionProcessor {

private:
	Stack operatorStack;

	Stack expressionTree;

	StaticQueue *expressionQueue;

public:
	ExpressionProcessor() {
		expressionQueue = new StaticQueue();
		operatorStack = Stack();
		expressionTree = Stack();
	}

	void ProcessFiles();

	void DisplayExpressionList();

	void ProcessExpressionList();

	void DisplayTraversedExpressionTree(int fileId);

	void EvaluateExpression(int fileId);

	int GetPriorityStack(string stringOperator);

	int GetPriorityElement(string stringOperator);

	bool CheckIfNumber(string elementOperator);

};