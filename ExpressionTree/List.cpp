#include "TreeNode.h"
#include "List.h"

using namespace std;

int List::Length() {
	int cont = 0;

	TreePointerNode aux = head;
	if (IsEmpty()) {
		return cont;
	}
	else {
		while (aux != NULL) {
			aux = aux->NextNode;
			cont++;
		}
		return cont;
		cout << endl;
	}

}

void List::Add(TreePointerNode value)
{
	if (IsEmpty()) {
		head = value;//new TreeNode(value);
	}
	else
	{
		TreePointerNode aux = head;

		while (aux->NextNode != NULL) {
			aux = aux->NextNode;
		}
		aux->NextNode = value;//new TreeNode(value);
	}
}

TreePointerNode List::Remove()
{
	TreePointerNode lastElement = NULL;
	if (head == NULL) {
		cout << "Empty Here \n\n";
	}
	else if (head->NextNode == NULL)
	{
		lastElement = head;
		head = NULL;
	}
	else {

		TreePointerNode aux = head;
		while (aux->NextNode->NextNode != NULL) {
			aux = aux->NextNode;
		}

		lastElement = aux->NextNode;
		aux->NextNode = NULL;
	}

	return lastElement;
}

void List::Display()
{
	TreePointerNode aux;
	if (head == NULL) {
		cout << "Empty Here \n\n";
	}
	else
	{
		aux = head;
		while (aux)
		{
			cout << aux->element << endl;
			aux = aux->NextNode;
		}
		cout << endl;
	}
}

string List::DisplayLastElementInfo()
{
	if (head == NULL) {
		return "Empty here";
	}

	if (head->NextNode == NULL)
	{
		return head->element;
		
	}
	else {

		TreePointerNode aux = head;
		while (aux->NextNode->NextNode != NULL) {
			aux = aux->NextNode;
		}

		return aux->NextNode->element;
	}

}
