#include "List.h"
#include "FileLoader.h"
#include "ExpressionProcessor.h"
#include "Stack.h"
#include "BinaryTree.h"
#include <iostream>
#include <fstream> 
using namespace std;

void ExpressionProcessor::ProcessFiles() {
	FileLoader loader;

	loader.LoadFiles(*(this->expressionQueue));
	
	DisplayExpressionList();

	ProcessExpressionList();
}

void ExpressionProcessor::DisplayExpressionList() {
	cout << "START Lectura de Archivos \n"  << endl;
	this->expressionQueue->Display();
	cout << "END  Lectura de Archivos " << endl;
	cout << "     " << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "     " << endl;
}

void ExpressionProcessor::ProcessExpressionList() {

	int count = this->expressionQueue->Length();
	
	for (int i = 0; i < count; i++)
	{
		cout << "START Display Expression List " + to_string(i + 1) << "\n\n" << endl;
		std::ofstream outfile("Expresion " + to_string(i + 1) +".txt");
		PointerNode node = this->expressionQueue->Pop();
		
		while (node != NULL)
		{
			if (CheckIfNumber(node->element)) {
				outfile << "Pila de expresion Vacia e inserta " << node->element << "\n\n";
				cout << "Elemento es un numero que se inserta en la Pila de Numeros  "<< node->element << "\n\n" ;
				this->expressionTree.Push(new TreeNode(node->element));
			}
			else {
				if (!CheckIfNumber(node->element) && this->operatorStack.IsEmpty()) {
					outfile << "Pila de operador Vacia e inserta " << node->element << "\n\n";
					cout << "Elemento es un operador que se inserta en la Pila de Operadores  " << node->element << "\n\n";
					this->operatorStack.Push(new TreeNode(node->element));
				}
				else {
					int commingElementPriority = GetPriorityElement(node->element);
					int topOperator = GetPriorityStack(this->operatorStack.Peek());
					if (commingElementPriority > topOperator && node->element != ")") {
						outfile << "Prioridad de \"" << node->element << "\" que viene de lista  " << commingElementPriority << " > " << GetPriorityStack(this->operatorStack.Peek()) << " \"" << this->operatorStack.Peek() << "\" Que Prioridad Pila Operadores , Entra Pila Operadores \n\n";
						cout << "Elemento es mayor prioridad a la prioridad del operador se inserta en la Pila de Operadores " << node->element << "\n\n";
						this->operatorStack.Push(new TreeNode(node->element));
					}
					else if (commingElementPriority <= topOperator && node->element != ")") {
						outfile << "Prioridad de \"" << node->element << "\" que viene de lista  " << commingElementPriority << " <= " << GetPriorityStack(this->operatorStack.Peek()) << " \"" << this->operatorStack.Peek() << "\"  Que Prioridad Pila Operadores " << "\n\n";
						outfile << "Saca Tope de operadores, Saca Tope (Der), Saca tope (Izq) y Inserta en Pila Expressiones" << "\n\n";
						cout << "Elemento es menor o igual prioridad a la prioridad del operador  " << node->element << "\n\n";
						cout << "Remover el tope de operador, El tope de pila expression, El tope de pila expression otra vez \n\n";
						cout << "y Se Inserta el nuevo operador en la pila de operadores   \n\n";
						TreePointerNode top = this->operatorStack.Remove();
						outfile << "Remueve tope operadores " << top->element << " \n\n";
					    TreePointerNode right = this->expressionTree.Remove();
						outfile << "Remueve tope Expresion " << right->element << " \n\n";
					    TreePointerNode left = this->expressionTree.Remove();
						outfile << "Remueve tope Expresion " << left->element << " \n\n";
					    top->SetRight(right);
						outfile << "Pone el Nodo Derecho  " << right->element << " \n\n";
					    top->SetLeft(left);
						outfile << "Pone el Nodo Izquierdo  " << left->element << " \n\n";
					    this->expressionTree.Push(top);
						outfile << "Inserta Nodo Arbol en Pila " << " \n\n";
					    this->operatorStack.Push(new TreeNode(node->element));
						outfile << "Inserta Nuevo Operador Pila Operadores " << " \n\n";
					}
					else if (node->element == ")") {
						cout << "El Elemento es \")\" , se mueven elementos a la pila de expressiones y se ignoran parentesis   \n\n";
						outfile << "El Elemento es \")\" , se mueven elementos a la pila de expressiones y se ignoran parentesis   \n\n";
						do{
							
							TreePointerNode top = this->operatorStack.Remove();
							outfile << "Remueve tope operadores \"" << top->element << "\" \n\n";
							if (top->element != "(")
							{
								TreePointerNode right = this->expressionTree.Remove();
								outfile << "Remueve tope Expresion  \"" << right->element << "\" \n\n";
								TreePointerNode left = this->expressionTree.Remove();
								outfile << "Remueve tope Expresion  \"" << left->element << "\" \n\n";
								top->SetRight(right);
								outfile << "Pone el Nodo Derecho  \"" << right->element << "\" \n\n";
								top->SetLeft(left);
								outfile << "Pone el Nodo Izquierdo  \"" << left->element << "\" \n\n";
								this->expressionTree.Push(top);
								outfile << "Inserta Nodo Arbol  " << " \n\n";
							}
							
						} while (this->operatorStack.Peek() != "(");
					}
				}
			}
			node = node->NextNode;
		}
		if (!this->operatorStack.IsEmpty())
		{
			cout << "Todos los elementos fuero sacados de la Cola pero quedan Elementos por mover desde la pila de operadores \n\n";
		}
		
		while (!this->operatorStack.IsEmpty()) {
			outfile << "Termina de Mover Elementos de la Pila de Operadores  " << " \n\n";
			TreePointerNode top = this->operatorStack.Remove();
			if (top->element != "(") {
				cout << "Elemento es un operador que se remueve en la Pila de Operadores y se inserta en la pila de expressiones \"" << top->element << "\"\n\n";
				TreePointerNode right = this->expressionTree.Remove();
				outfile << "Remueve tope Expresion  \"" << right->element << "\" \n\n";
				TreePointerNode left = this->expressionTree.Remove();
				outfile << "Remueve tope Expresion  \"" << left->element << "\" \n\n";
				top->SetRight(right);
				outfile << "Pone el Nodo Derecho  \"" << right->element << "\" \n\n";
				top->SetLeft(left);
				outfile << "Pone el Nodo Izquierdo  \"" << left->element << "\" \n\n";
				this->expressionTree.Push(top);
				outfile << "Inserta Nodo Arbol  " << " \n\n";
			}
		}
		outfile.close();
		cout << "     " << endl;
		cout << "---------------------------------------------------------" << endl;
		cout << "     " << endl;

		DisplayTraversedExpressionTree(i + 1);
		this->expressionTree.~Stack();
		cout << "END Display Expression List file " + to_string(i + 1) << endl;
		cout << "     " << endl;
		cout << "---------------------------------------------------------" << endl;
		cout << "     " << endl;
	}
	
}

int ExpressionProcessor::GetPriorityStack(string stringOperator) {
	if (stringOperator == "(") {
		return 0;
	}
	else if (stringOperator == "+" || stringOperator == "-") {
		return 1;
	}
	else if (stringOperator == "*" || stringOperator == "/") {
		return 2;
	}
	else if (stringOperator == "^") {
		return 3;
	}
	else {
		return -1;
	}
}

int ExpressionProcessor::GetPriorityElement(string stringOperator) {
	
	if (stringOperator == "+" || stringOperator == "-") {
		return 1;
	}
	else if (stringOperator == "*" || stringOperator == "/") {
		return 2;
	}
	else if (stringOperator == "^") {
		return 4;
	}
	else if (stringOperator == "(") {
		return 5;
	}
	else {
		return -1;
	}
}

bool ExpressionProcessor::CheckIfNumber(string elementOperator) {

	try {
		int num = stoi(elementOperator);
		return true;
	}
	catch (std::exception& e) {
		return false;
	}
}

void ExpressionProcessor::DisplayTraversedExpressionTree(int fileId) {
	BinaryTree tree;

	cout << "Recorridos del Arbol de Expresion \n\n" << endl;

	cout << "En Orden \n" << endl;
	tree.InOrder(this->expressionTree.head);
	cout << "\n \n  " << endl;

	cout << "En Pre Orden \n " << endl;
	tree.PreOrder(this->expressionTree.head);
	cout << "\n \n  " << endl;

	cout << "En Post Orden \n  " << endl;
	tree.PostOrder(this->expressionTree.head);
	cout << "\n \n  " << endl;

	EvaluateExpression(fileId);
}

void ExpressionProcessor::EvaluateExpression(int fileId) {

	BinaryTree tree;

	cout << "Evaluar resultado de Arbol de Expresion \n" << endl;
	try
	{
		ofstream outfile("Expresion Evaluated " + to_string(fileId) + ".txt");
		int result = tree.EvaluateExpression(this->expressionTree.head, &(outfile));
		outfile << "Resultado Final Expresion es : " << result << "\n\n";
		cout << "El Resultado Final es : " + to_string(result) << "\n" << endl;
	}
	catch (std::overflow_error& e)
	{
		cout << "El Resultado Final es Indefinido dado que hay division entre 0 \n" << endl;
	}
}