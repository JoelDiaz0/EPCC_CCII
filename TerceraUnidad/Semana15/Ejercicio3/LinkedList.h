#pragma once

#include <iostream>
#include "Node.h"

class LinkedList {
    int size;
    Node* head;
public:

    LinkedList();
    LinkedList(int);
    LinkedList(const LinkedList&);

    ~LinkedList();

    void insert(int);

    void removeByValue(int);
    void removeByPosition(int);

    bool search(int value);
    void mostrar();

    friend std::ostream& operator <<(std::ostream& salida1, const LinkedList& C);
    LinkedList& operator=(const LinkedList& L);
};



