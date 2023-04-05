#pragma once
#include <iostream>
#include <fstream>
#include "StaticQueue.h"

using namespace std;

class FileLoader {

public:
	FileLoader() {}

	void LoadFiles(StaticQueue& staticQueue);
};