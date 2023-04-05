#include "TreeNode.h"
#include "BinaryTree.h"
#include <iostream>
#include <fstream> 
using namespace std;

void BinaryTree::InOrder(TreeNode* node) {
	if (node == NULL) {
		return;
	}
	else {
		InOrder(node->GetLeft());
		cout << node->GetElement() << "  ";
		InOrder(node->GetRight());
	}
}

void BinaryTree::PreOrder(TreeNode* node) {
	if (node == NULL) {
		return;
	}
	else {
		cout << node->GetElement() << "  ";
		PreOrder(node->GetLeft());
		PreOrder(node->GetRight());
	}
}

void BinaryTree::PostOrder(TreeNode* node) {
	if (node == NULL) {
		return;
	}
	else {
		PostOrder(node->GetLeft());
		PostOrder(node->GetRight());
		cout << node->GetElement() << "  ";
	}
}

bool BinaryTree::CheckIfNumber(string element) {

	try {
		int num = stoi(element);
		return true;
	}
	catch (std::exception& e) {
		return false;
	}
}

int BinaryTree::EvaluateExpression(TreeNode* node, ofstream* outfile) {
	if (node == NULL) {
		return 0;
	}

	if (node->GetLeft() == NULL && node->GetRight() == NULL) {
		return stoi(node->GetElement());
	}

	int leftValue = EvaluateExpression(node->GetLeft(), outfile);

	int rightValue = EvaluateExpression(node->GetRight(), outfile);

	// Evaluate Expression
	string operatorToApply = node->GetElement();

	if (operatorToApply == "+") {
		*(outfile) << "Suma de " << leftValue << " + " << rightValue << "\n\n";
		return leftValue + rightValue;
	}
	else if (operatorToApply == "-") {
		*(outfile) << "Resta de " << leftValue << " - " << rightValue << "\n\n";
		return leftValue - rightValue;
	}
	else if (operatorToApply == "*") {
		*(outfile) << "Multiplicacion de " << leftValue << " * " << rightValue << "\n\n";
		return leftValue * rightValue;
	}
	else if (operatorToApply == "/") {
		if (rightValue == 0)
		{
			*(outfile) << "Error Division entre cero" << "\n\n";
			throw std::overflow_error("Divide by zero exception");
		}
		*(outfile) << "Division de " << leftValue << " / " << rightValue << "\n\n";
		return leftValue / rightValue;
	}
	else {
		*(outfile) << "Potencia de " << leftValue << " / " << rightValue << "\n\n";
		int exp = rightValue;
		if (exp == 0)
		{
			return 1;
		}
		else {
			int base = leftValue;
			int result = leftValue;
			while (exp != 1) {

				result *= base;
				--exp;
			}
			return result;
		}
	}

}