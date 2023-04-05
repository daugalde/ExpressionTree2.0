#include "Node.h"
#include <iostream>
#include <fstream>
#include "FileLoader.h"
#include <string>

using namespace std;

void FileLoader::LoadFiles(StaticQueue& staticQueue) {

	for (int i=0; i < 5; i++) {
		PointerNode node = NULL;
		string fileId = to_string(i + 1);
		string str;
		ifstream file(("Arch" + fileId + ".txt"));

		while (!file.eof()) {
			getline(file, str);
			if (node == NULL)
			{
				node = new Node(str);
			}
			else {
				PointerNode aux = node;

				while (aux->NextNode != NULL) {
					aux = aux->NextNode;
				}
				aux->NextNode = new Node(str);
			}
			
		}
		staticQueue.Push(node);
	}
}
