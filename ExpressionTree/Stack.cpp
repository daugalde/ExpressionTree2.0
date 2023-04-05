#include "Stack.h"

using namespace std;

int Stack::Length() {
	return List::Length();
}

string Stack::Peek() {
	return List::DisplayLastElementInfo();
};

void Stack::Push(TreePointerNode value) {
	List::Add(value);
};

TreePointerNode Stack::Pop() {
	return List::Remove();
};

void Stack::Display() {
	List::Display();
};

