#include <iostream>
#include "StaticQueue.h"
using namespace std;

int StaticQueue::Length()
{
    int cont = 0;

    for (int i = 0; i < 5; i++)
    {
        if (this->StaticQueueArray[i] != NULL) {
            cont++;
        }

    }
    return cont;
};

bool StaticQueue::IsEmpty()
{
    return this->back < this->front;
}

void StaticQueue::Push(PointerNode node)
{
    if (back < 5 - 1) {
        ++back;
        StaticQueueArray[back] = node;

    }
    else {
        cout << "La cola esta llena";
    }
}

PointerNode StaticQueue::Pop()
{
    if (!IsEmpty()) {
        front++;
        return StaticQueueArray[front - 1];
    }
    else {
        cout << "La cola esta vacia";
    }
}

void StaticQueue::Display() {
    for (int i = 0; i < back + 1; i++) {
        
        if (IsEmpty()) {
            cout << "Cola esta vacia";
        }
        else
        {
            if (StaticQueueArray[i] != NULL)
            {
                PointerNode aux = StaticQueueArray[i];
                while (aux)
                {
                    cout << " " << aux->element;
                    aux = aux->NextNode;
                }
                cout << "\n" << endl;
            }
            
        }
    }
}

