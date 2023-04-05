#pragma once
#include <iostream>
#include "List.h"
#include "Node.h"
using namespace std;

class StaticQueue
{
private:
    int front;
    int back;
    PointerNode StaticQueueArray[5];

public:
    StaticQueue() {
        front = 0;// First In
        back = -1;// Last
        for (int i = 0; i < 5; i++) {
            StaticQueueArray[i] = NULL;
        }
    }

    int Length();
    bool IsEmpty();
    void Push(PointerNode node);
    PointerNode Pop();
    void Display();
};